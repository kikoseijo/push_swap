make re && ./push_swap "2 1 3 6 5 8"
make re && ./push_swap "2 1 3 6 5 8 10 -30 -10"
make re && lldb ./push_swap "2 1 3 6 5 8"
make re && valgrind --leak-check=full --track-origins=yes  ./push_swap "2 1 3 6 5 8"
# Radix single function sort.
kcc src/radix_sort.c && ./a.out && rm -rf a.out

# checker_OS validator
chmod 755 checker_Mac
ARG="2 1 42 3 6 5 8 30 10 20 33"; ./push_swap $ARG | ./checker_Mac $ARG
ARG=`ruby -e "puts (-50..49).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
ARG=`ruby -e "puts (-250..249).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_Mac $ARG
ARG=`ruby -e "puts (-500..499).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_Mac $ARG


ARG="-72 -248 -168 -5 -19 -194 -64 28 -107 146 23 97 138 -98 -245 107 -119 8 -85 -211 62 -142 -58 -74 248 156 65 223 88 159 136 178 -226 -53 -70 16 22 -49 -16 -155 -215 -11 61 -100 75 -206 76 224 -173 -196 -59 -157 -71 129 -152 -247 30 -243 103 225 166 -78 -122 -26 77 221 -9 49 31 -37 105 -139 -80 -45 19 59 -22 57 -210 38 -103 7 126 -127 -191 132 -101 211 -140 141 53 24 -219 -178 140 -189 -84 29 -117 -228 -213 -128 -231 -195 171 213 -241 112 204 148 220 -169 196 -1 116 -136 -81 234 82 -36 -34 43 239 212 228 -2 93 -154 -120 -52 -237 189 90 39 67 10 145 143 -186 -68 -132 -102 -232 -223 -67 109 100 -14 72 -171 -175 172 244 182 -29 133 -214 -193 -39 161 92 236 -62 144 -239 -57 -220 233 -235 217 37 180 -92 56 210 -216 -123 164 -236 193 15 79 186 -73 215 17 165 54 -187 -227 -249 190 -170 85 -105 21 -87 -93 149 -126 242 68 -145 -166 -124 -229 91 115 238 102 163 -209 -15 -230 -6 -12 227 36 -177 -8 60 170 207 -31 32 94 -13 -20 -149 157 162 -174 51 -161 187 40 201 247 195 45 106 14 58 -61 104 66 150 -133 -27 -41 -225 245 41 203 -17 9 -54 18 205 -129 -164 74 -114 -83 -79 -89 169 128 -158 -30 249 -96 -184 174 160 -167 -24 200 -160 25 -55 -111 -202 -121 -33 -90 -233 219 -21 -118 -112 70 142 137 241 230 -207 -222 -60 -162 198 81 214 -108 -66 89 11 4 118 226 52 -23 -56 -180 -44 86 27 44 -250 -176 -32 -25 -134 64 -10 12 -201 -63 73 78 181 71 -40 131 -221 155 -43 -217 -42 120 208 246 35 87 -65 -172 153 33 216 108 -106 99 -47 -159 -88 47 151 96 194 130 -104 -135 13 -76 2 122 243 191 -212 -204 117 218 -109 176 -130 179 135 231 34 125 202 209 168 -48 134 121 152 154 -113 235 -3 232 -115 69 -188 -28 184 -179 -125 1 -38 -50 -190 114 173 185 123 192 147 -185 183 206 -182 -197 124 -99 -200 113 197 -86 -4 -137 -224 -163 55 119 -35 -131 -95 -18 -110 -138 -94 26 -203 229 -156 -91 240 98 -148 95 111 -205 -181 -153 -146 -165 83 80 -218 101 -238 -97 6 0 -244 -147 -192 -77 -143 -183 222 -51 -75 -141 -69 199 -144 -234 50 84 -199 -198 20 46 -116 -240 48 -242 -151 -208 63 177 158 -82 167 110 -246 188 -7 3 42 -46 5 139 175 -150 127 237"; ./push_swap $ARG | ./checker_Mac $ARG

#
#	EVALUATION
#
./push_swap hola que pasa
./push_swap 3 4 5 5
./push_swap 3 4 5 554646554646546554654654
./push_swap
./push_swap 42
./push_swap 0 1 2 3
./push_swap 0 1 2 3 4 5 6 7 8 9
./push_swap 0 1 2 3 4 5 6 7 8 9

ARG="2 1 0"; ./push_swap $ARG | ./checker_MAC $ARG
# Check that the checker program displays "OK" and that the
# size of the list of instructions from push_swap is 2 OR 3.

ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker_MAC $ARG
# Check that the checker program displays "OK" and that the
# size of the list of instructions from push_swap isn't more
# than 12. Kudos if the size of the list of instructions is 8.

ARG="<5 random values>"; ./push_swap $ARG | ./checker_MAC $ARG
ARG="1 333 456 32 -3"; ./push_swap $ARG | ./checker_MAC $ARG
# Check that the checker program displays "OK" and that the
# size of the list of instructions from push_swap isn't more
# than 12. Otherwise this test fails. You'll have to
# specifically check that the program wasn't developed to only
# answer correctly on the test included in this scale. You
# should repeat this test couple of times with several
# permutations before you validate it.

ARG="<100 random values>"; ./push_swap $ARG | ./checker_MAC $ARG
ARG="-13 -43 -26 15 23 -40 -5 -14 33 -35 41 29 -17 22 -19 45 -3 30 38 -32 -30 -25 -47 43 -9 34 -8 21 1 19 -37 11 44 -44 37 42 -46 -1 8 48 12 -15 46 -11 13 28 -49 9 39 -50 -27 -22 16 7 -33 5 49 0 24 -24 40 -48 -21 47 -41 4 26 10 6 -31 27 32 36 -28 -34 -42 -18 -45 -4 14 20 17 -10 -20 -12 3 -7 -38 -6 25 -29 2 31 -23 -39 -36 -2 35 -16 18"; ./push_swap $ARG | ./checker_MAC $ARG
# Check that the checker program displays "OK"
# and that the size of the list of instructions.
# Give points in accordance:
# - less than 700: 5
# - less than 900: 4
# - less than 1100: 3 -----> 1084
# - less than 1300: 2
# - less than 1500: 1

ARG="<500 random values>"; ./push_swap $ARG | ./checker_MAC $ARG
ARG="101 192 25 -133 -108 139 -200 113 49 118 126 46 201 238 -122 -6 173 54 -199 124 5 136 239 216 -179 -205 -246 -3 -68 43 160 -164 31 74 179 209 30 -120 -224 119 186 117 38 149 98 -60 -168 150 -80 213 249 -209 185 27 79 50 177 142 -228 -64 199 -166 21 235 72 -181 -237 127 245 129 -163 -87 12 210 -51 68 60 222 95 0 -50 78 -104 -42 205 240 110 -63 200 -134 -214 -70 -24 -59 167 -196 -132 -44 -71 194 -56 -154 -186 -5 -26 -190 151 140 40 184 -172 109 134 -43 -162 -41 -222 107 15 -193 190 7 111 22 69 -75 35 -78 -116 220 -140 76 -175 -61 -57 -86 28 -30 -194 -167 193 -15 -107 51 -47 -242 37 -36 23 244 248 114 -227 -25 211 -170 -124 -127 243 -231 -188 59 138 -21 11 -58 -110 -53 -38 -128 8 102 197 -147 -125 -221 -95 104 247 77 -91 -65 217 -33 120 171 52 225 -7 -213 -238 -207 143 67 -148 -212 82 -247 116 29 -62 -27 -201 90 214 -101 221 -55 -52 92 219 65 112 -102 9 88 80 70 -90 -98 -72 -145 178 -225 -73 64 158 231 -114 195 166 -48 -32 -126 -219 187 -138 146 -143 -112 18 89 -92 228 115 75 -177 -81 145 -191 97 174 -189 132 -240 19 -180 203 -113 227 -182 42 168 -226 -12 133 175 -49 152 -40 45 -106 164 246 -141 131 -156 242 -218 -239 165 -89 -37 -160 -192 91 -28 170 155 204 20 -137 6 -115 -217 81 48 4 130 16 -198 -171 -10 -121 -103 176 -131 156 33 -232 -206 -84 -97 -151 100 -184 -187 -82 -100 105 -142 -185 224 83 135 -233 -158 161 1 96 -123 34 226 -244 153 -220 73 -46 -243 -35 32 -39 3 -165 -34 36 13 -16 -45 181 -139 236 157 202 232 -22 -174 -85 -119 -105 233 -211 -9 108 87 56 -130 -234 -99 -230 182 -109 148 99 -250 -157 -249 183 -74 208 -31 -149 94 86 -11 -208 -129 123 198 61 -136 180 -66 -248 55 234 128 -4 -117 215 -13 2 -173 84 -245 162 66 189 -1 137 144 -69 -135 -155 -176 -79 -215 230 17 -223 188 44 106 241 93 -17 -203 122 147 53 229 191 -76 163 -77 -19 -118 -197 -229 41 -235 -18 -202 125 154 172 -152 -29 218 -14 -54 196 -216 159 -8 -144 121 62 -94 57 39 85 -146 -150 26 -20 223 103 -83 -111 207 -236 206 -210 169 24 -23 47 212 -241 -169 63 -153 14 -96 -204 -93 58 -183 -178 -161 10 237 -159 71 -67 141 -2 -88 -195"; ./push_swap $ARG | ./checker_MAC $ARG
# Check that the checker program displays "OK" and
# that the size of the list of instructions
# - less than 5500: 5
# - less than 7000: 4	------> 6784
# - less than 8500: 3
# - less than 10000: 2
# - less than 11500: 1

./checker hola
# - Run checker with non numeric parameters. The program must
# display "Error".

./checker 5 4 3 4
# - Run checker with a duplicate numeric parameter. The program
# must display "Error".

./checker 5 4 3 554646554646546554654654
# - Run checker with only numeric parameters including one greater
# than MAXINT. The program must display "Error".

./checker
# - Run checker without any parameters. The program must not
# display anything and give the prompt back.

./checker 1 4 2 20 -10
# - Run checker with valid parameters, and write an action that
# doesn't exist during the instruction phase. The program must
# display "Error".

./checker 1 4 2 20 -10
# - Run checker with valid parameters, and write an action with
# one or several spaces before and/or after the action during
# the instruction phase. The program must display "Error".
