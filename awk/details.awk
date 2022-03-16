BEGIN {
FS = ":"
print "Going to read the dinosaur database..."
}
{ print $1 }
{ print "\tType: " $2 }
{ print "\tLength: " $3 " meters" }
$4 == "" { print "\tWeight: Unknown" }
$4 != "" { print "\tWeight: " $4 " kilograms" }
$5 == "H" { print "\tDiet: Herbivorous" }
$5 == "C" { print "\tDiet: Carnivorous" }
$5 == "O" { print "\tDiet: Omnivorous" }
{ print "\tLived " $6 " million years ago" }
{ print "\tFossils found in" }
n = split($7, clist, ", ")
for (i=1; i<=n; ++i) { print "\t\t" clist[i] }
END { print "That is all I have. Bye..." }