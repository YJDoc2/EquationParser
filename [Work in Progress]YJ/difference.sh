touch diffV.txt
echo '-----START------' >> diffV.txt
echo ''>> diffV.txt
echo '-----CONSTANTS.C------' >> diffV.txt
diff ./Unstable/constants.c './Mark II/constants.c' >> diffV.txt
echo ''>> diffV.txt
echo '-----TYPEDEF.C------' >> diffV.txt
diff ./Unstable/typedef.c './Mark II/typedef.c' >> diffV.txt
echo ''>> diffV.txt
echo '-----VARIABLES.C------' >> diffV.txt
diff ./Unstable/variables.c './Mark II/variables.c' >> diffV.txt
echo ''>> diffV.txt