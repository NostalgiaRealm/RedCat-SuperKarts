/*
 * FUN_0040b698 at 0040b698
 * int __register FUN_0040b698(int param_1, int param_2)
 * Address ranges: 0040b698-0040b6fb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0040b698(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int local_10;
  int local_c;
  
  local_10 = 0;
  iVar2 = local_10;
  if ((((0 < param_2) && (iVar1 = FUN_00403dd0(param_1), iVar2 = local_10, param_2 <= iVar1)) &&
      (iVar2 = param_2, 1 < param_2)) && (iVar2 = param_2, DAT_0047d5b8 != '\0')) {
    FUN_0040b624(param_1,param_2 + -1,&local_c,&local_10);
    if ((local_c < param_2 + -1) || (iVar2 = FUN_00403dd0(param_1), iVar2 <= local_10)) {
      local_10 = 0;
      iVar2 = local_10;
    }
    else {
      iVar2 = local_10 + 1;
    }
  }
  local_10 = iVar2;
  return local_10;
}

