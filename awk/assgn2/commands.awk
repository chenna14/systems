{ OFS = ":"
  
    if(($2 == "") && ($3 == "")) {balance = $4;print "Bank account created with: " $4}
    if(($2 != "") && ($3 == "")) {balance = balance+$2;print "Amount added to the bank: " $2}
    if(($2 == "") && ($3 != "")) {balance = balance - $3;print "Amount debited from the bank: " $3}
  $4 = balance
  

    print $0 > "test.txt"
}

END{
    
}