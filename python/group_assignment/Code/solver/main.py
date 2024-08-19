from expressions.expression import Expression
from expressions.expression_builder import ExpressionBuilder
from solver.solver import solve, is_sat, satisfies, not_satisfies, is_tautology, is_contradiction

if __name__ == "__main__":
    expressions = [
        ExpressionBuilder().variable("p").disjunction(ExpressionBuilder().variable("p").negate().build()).build(),
        ExpressionBuilder().variable("p").conjunction(ExpressionBuilder().variable("q").build()).build(),
        ExpressionBuilder().constant(False).implicate(ExpressionBuilder().variable("q").build()).build(),
        ExpressionBuilder().variable("p").implicate(ExpressionBuilder().variable("p").negate().build()).build(),
        ExpressionBuilder().variable("p").conjunction(ExpressionBuilder().variable("p").negate().build()).build(),
        ExpressionBuilder().variable("p").exclusive_disjuction(ExpressionBuilder().variable("q")\
        .implicate(ExpressionBuilder().variable("r").build()).build()).build(),
        ExpressionBuilder().variable("p").disjunction(ExpressionBuilder().variable("q").build()).negate().\
        iff(ExpressionBuilder().variable("p").negate().conjunction(ExpressionBuilder().variable("q").negate().build()).build()).build()
    ]

    for expr in expressions:
        print("Expression: ", str(expr))
        print("Variables: ", expr.variables())
        print("All possible interpretations:")

        for interpretation in expr.interpretations():
            print(interpretation)

        print("Is the expression satisfiable? ", 'Yes' if is_sat(expr) is not None else 'No')
        print("Is the expression a tautology? ", 'Yes' if is_tautology(expr) else 'No')
        print("Is the expression a contradiction? ", 'Yes' if is_contradiction(expr) else 'No')

        print("Satisfied Interpretations:")
        for interpretation in satisfies(expr) or []:
            print(interpretation)
        
        print("Dissatisfied Interpretations:")
        for interpretation in not_satisfies(expr) or []:
            print(interpretation)
