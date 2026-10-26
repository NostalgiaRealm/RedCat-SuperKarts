/*
 * FUN_0040b6fc at 0040b6fc
 * int __register FUN_0040b6fc(int param_1, int param_2)
 * Address ranges: 0040b6fc-0040b75b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0040b6fc(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int local_10;
  int local_c;
  
  local_10 = 0;
  iVar1 = local_10;
  if (0 < param_2) {
    iVar1 = FUN_00403dd0(param_1);
    if (iVar1 < param_2) {
      param_2 = FUN_00403dd0(param_1);
    }
    iVar1 = param_2;
    if (DAT_0047d5b8 != '\0') {
      FUN_0040b624(param_1,param_2,&local_c,&local_10);
      iVar2 = FUN_00403dd0(param_1);
      iVar1 = local_10;
      if (iVar2 < local_10) {
        iVar1 = FUN_00403dd0(param_1);
      }
    }
  }
  local_10 = iVar1;
  return local_10;
}

