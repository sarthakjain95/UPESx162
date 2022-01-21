
''''
Implement the following things on PyTorch:-(Python)
    Explore the tools with different options like
    installation
    tensor creation deletion
    tensor manipulation

2 Write a Program for Matrix Addition
3 Write a Program for Matrix Multiplication
4 Write a Program for Matrix Transpose
'''

import torch 
# Tensor creation 
tensor = torch.rand(2, 5, 5)
print(tensor)
# Tensor Manipulation 
tensor[0][0][0] = 32
print(tensor)
# Deleting tensor/variable
del tensor
print("Deleted tensor")
# Matrix Addition
mat1 = torch.rand(2, 2)
mat2 = torch.rand(2, 2)
print(mat1)
print(mat2)
addition_result = torch.zeros(mat1.shape)
for y in range(mat1.shape[0]):
    for x in range(mat1.shape[1]):
        addition_result[y][x] = mat1[y][x] + mat2[y][x]
print("Addition result")
print(addition_result)
# Element wise Matrix Multiplication
element_wise = torch.zeros(mat1.shape)
for y in range(mat1.shape[0]):
    for x in range(mat1.shape[1]):
        element_wise[y][x] = mat1[y][x] * mat2[y][x]
print("Element wise multiplication result")
print(element_wise)
# Matrix transpose
mat = torch.rand(3, 3)
print(mat)
for y in range(mat.shape[0]):
    for i in range(y+1, mat.shape[0]):
        tmp = float(mat[y][i])
        mat[y][i] = mat[i][y]
        mat[i][y] = tmp
print("Matrix Transpose result")
print(mat)
