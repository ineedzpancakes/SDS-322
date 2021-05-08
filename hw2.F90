module NewtonsMethod
implicit none
        contains
                real function f(x)
                        real, intent(in) :: x
                        f = x ** 3
                end function f
                real function p(x)
                        real, intent(in) :: x
                        p = 3 * (x ** 2)
                end function p
                real function x_new(x)
                        real, intent(in) :: x
                        x_new = x - f(x) / p(x)
                end function x_new
                integer function iterations(x)
                        real, intent(in) :: x
                        real :: x_zero, x_one
                        integer :: n_iter = 0
                        real, parameter :: my_epsilon = .0001
                        integer, parameter :: max_its = 100
                        
                        n_iter = 0
                        x_zero = x
                        do
                                x_one = x_new(x)
                                n_iter = n_iter + 1
                                if (abs(x_one - x_zero) <= my_epsilon) then
                                        exit
                                else if (n_iter >= max_its) then
                                        iterations = max_its
                                end if
                                x_zero = x_one
                        end do
                        iterations = n_iter
                end function iterations
end module NewtonsMethod

program hw2
use NewtonsMethod
implicit none
real :: x_guess
integer :: i = 1
real, dimension(50) :: A
real, dimension(50) :: B
x_guess = 0.0
do while (x_guess <= 5.0)
        A(i) = iterations(x_guess)
        B(i) = x_guess
        print *, 'Iterations: ', A(i), 'x Value:', B(i)
        i = i + 1
        x_guess = x_guess + 0.1
end do
end program hw2
