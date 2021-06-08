module NewtonsMethod
implicit none
        contains
                complex function f(z)
                        complex, intent(in) :: z
                        f = z ** 3
                end function f
                complex function p(z)
                        complex, intent(in) :: z
                        p = 3 * (z ** 2)
                end function p
                complex function z_new(z)
                        complex, intent(in) :: z
                        z_new = z - f(z) / p(z)
                end function z_new
                integer function iterations(z)
                        complex, intent(in) :: z
                        complex :: z_zero, z_one
                        integer :: n_iter = 0
                        real, parameter :: my_epsilon = .0001
                        integer, parameter :: max_its = 100
                        
                        n_iter = 0
                        z_zero = z
                        do
                                z_one = z_new(z)
                                n_iter = n_iter + 1
                                if (abs(z_one - z_zero) < my_epsilon) then
                                        exit
                                else if (n_iter == max_its) then
                                        iterations = max_its
                                end if
                                z_zero = z_one
                        end do
                        iterations = n_iter
                end function iterations
end module NewtonsMethod

program midterm
use NewtonsMethod
implicit none
complex :: z_guess
real :: x, a, stride = .01
x = -1.5
a = -1.5
do while (x < 1.5)
        a = -1.5
        do while (a < 1.5)
                z_guess = cmplx(x, a)
                print *, x, ',', a, ',', iterations(z_guess)
                a = a + stride
        end do
        x = x + stride
end do
end program midterm
