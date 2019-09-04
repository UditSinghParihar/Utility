import torch 
import numpy as np

x = torch.empty(5,3)
y = torch.rand(4,3)
z = torch.zeros(3,4, dtype=torch.long)
l1 = [3,4]
l2 = torch.tensor(l1)
print(x,y,z,l1,l2)

x = x.new_ones(2,3,dtype=torch.double)
y = torch.randn_like(x,dtype=torch.double)
print(x,y,x.size())

y += x
print(y,y.size())
y = y.view(6,1)
print(y)

z = torch.rand(6,3)
print(z)
z = torch.rand(9,-1)
print(z)

a = torch.tensor([x for x in xrange(10)])
print(a)

b = np.arange(20).reshape(20,1)
print(b, b.shape)

c = torch.tensor(b)
print(c,c[7],torch.t(c))

d = c.numpy()
print(d.reshape(d.shape[0],-1))

x = torch.arange(1,5).reshape(2,2)
x.requires_grad_(True)
print(x.requires_grad)
y = x+3
z = 4*y*y + 10
# z = z.mean()
z.backward(x)
print(x.grad)
