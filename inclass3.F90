program inclass2
implicit none

integer :: num
print *, 'Enter a number:'
read *, num
if (mod(num,3) == 0 .and. mod(num, 5) == 0) then
        print *, 'FizzBuzz'
else if (mod(num,3) == 0) then
        print *, 'Fizz'
else if (mod(num, 5) == 0) then
        print *, 'Buzz'
else
        print *, ''
end if
end program inclass2
