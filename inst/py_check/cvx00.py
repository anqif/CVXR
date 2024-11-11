import cvxpy as cp
beta = cp.Variable(nonneg = True)
objective = cp.Minimize(beta**2)
problem = cp.Problem(objective)
problem.solve(verbose = True)

