program inclass6
implicit none
integer :: i
real, dimension(100) :: r
call random_number(r)
r = r * 100
call array_sort(100, r)
do i = 1, 100
        print *, r(i)
end do

contains
        subroutine array_sort(n, arr)
                implicit none
                integer :: n, i
                logical :: swap = .true.
                real, dimension(n) :: arr
                real :: temp
                
                do while (swap == .true.)
                        swap = .false.
                        do i = 1, n - 1
                                if (arr(i) > arr(i + 1)) then
                                        temp = arr(i)
                                        arr(i) = arr(i + 1)
                                        arr(i + 1) = temp
                                        swap = .true.
                                end if
                        end do
                end do
        end subroutine array_sort
end program inclass6
