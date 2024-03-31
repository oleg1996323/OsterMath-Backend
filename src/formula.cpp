#include "formula.h"

#include "FormulaAST.h"

#include <algorithm>
#include <cassert>
#include <cctype>
#include <sstream>

using namespace std::literals;

std::ostream& operator<<(std::ostream& output, FormulaError fe) {
    output<<fe.ToString();
    return output;
}

namespace {
class Formula : public FormulaInterface {
public:
// Реализуйте следующие методы:
    explicit Formula(std::string expression)
    try:ast_(ParseFormulaAST(expression)){
        ref_ = std::vector<Position>(ast_.GetCells().begin(),ast_.GetCells().end());
    }
    catch (const FormulaException::exception& error){
        std::throw_with_nested(FormulaException(error.what()));
    }
    

    Value Evaluate(const SheetInterface& sheet) const override{
        try {
            double result = ast_.Execute(sheet);
            return result;
        }
        catch(FormulaError& error){
            return error;
        }
    }

    std::string GetExpression() const override{
        std::ostringstream stream;
        ast_.PrintFormula(stream);
        return stream.str();
    }

    std::vector<Position> GetReferencedCells() const override{
        std::vector<Position> result = ref_;
        return std::vector<Position>(std::make_move_iterator(result.begin()),std::make_move_iterator(std::unique(result.begin(),result.end())));
    }

private:
    void SetRef(std::vector<Position>&& refs){
        ref_ = refs;
    }

    FormulaAST ast_;
    std::vector<Position> ref_;
};
}  // namespace

std::unique_ptr<FormulaInterface> ParseFormula(std::string expression) {
    return std::make_unique<Formula>(std::move(expression));
}