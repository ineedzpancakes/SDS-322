program inclass1
implicit none
character(len = 10) :: user
integer :: a, b, c
real :: sphere, prism
user = 'Carlos'
a = 4
b = 5
c = 6
sphere = (4.0/3.0) * 3.14159265 * (4 ** 3)
prism = a * b * c
print *, 'Hello, ', user
print *, sphere
print *, prism
end program inclass1
