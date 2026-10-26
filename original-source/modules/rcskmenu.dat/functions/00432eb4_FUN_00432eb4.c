/*
 * FUN_00432eb4 at 00432eb4
 * int __register FUN_00432eb4(char * param_1, int param_2, char param_3)
 * Address ranges: 00432eb4-00432ec2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00432eb4(char *param_1,int param_2,char param_3)

{
  char cVar1;
  
  do {
    if (param_2 == 0) {
      return 0;
    }
    param_2 = param_2 + -1;
    cVar1 = *param_1;
    param_1 = param_1 + 1;
  } while (param_3 == cVar1);
  return param_2;
}

