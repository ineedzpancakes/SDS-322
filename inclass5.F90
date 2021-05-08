program inclass5
implicit none
real :: m, b, x, y_func, y_sub
m = 1.5
b = 2.5
x = 0.0
y_func = 0.0
y_sub = 0.0

do while (x <= 1.0)
        call line_subroutine(y_sub, m, x, b)
        y_func = line_function(m, x, b)
        print *, 'Line Subroutine:', y_sub, 'Line Function:', y_func
        x = x + 0.05
end do
contains
        subroutine line_subroutine(y_sub, m, x, b)
                real, intent(out) :: y_sub
                real, intent(in) :: m, x, b
                y_sub = m * x + b
        end subroutine line_subroutine
        
        real function line_function(m, x, b)
                real :: m, x, b
                line_function = m * x + b
        end function line_function
end program inclass5

