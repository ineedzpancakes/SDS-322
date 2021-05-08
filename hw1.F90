program hw1
implicit none

integer :: i, n, max_seq, current_seq
max_seq = 0
do i = 2, 1000
        n = i 
        current_seq = 0
        do while (n /= 1)
                if (mod(n, 2) /= 0) then
                        n = 3 * n + 1
                        current_seq = current_seq + 1
                else if (mod(n, 2) == 0) then
                        n = n / 2
                        current_seq = current_seq + 1
                end if
        end do
        if (current_seq > max_seq) then
                max_seq = current_seq
                print *, i
        end if
end do
end program hw1
