/*
 * FUN_004388d4 at 004388d4
 * undefined __register FUN_004388d4(int * param_1, int param_2, char param_3)
 * Address ranges: 004388d4-00438904
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004388d4(int *param_1,int param_2,char param_3)

{
  int iVar1;
  undefined4 extraout_ECX;
  
  FUN_00414aa4((int)param_1,param_2,param_3);
  if (param_3 == '\x01') {
    iVar1 = FUN_0043806c((int)param_1);
    if (param_2 == iVar1) {
      FUN_004384b8(param_1,0,extraout_ECX);
    }
  }
  return;
}

