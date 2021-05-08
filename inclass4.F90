program inclass3
implicit none

integer :: i, j, k
do i = 1, 100
        do j = 1, 100
                do k = 1, 100
                        if ((i*i) + (j*j) == (k*k) .and. k < 100) then
                                print *, i, ' ', j, ' ', k
                        end if
                end do
        end do
end do
end program inclass3
