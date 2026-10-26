/*
 * FUN_00426ca4 at 00426ca4
 * undefined __register FUN_00426ca4(int * param_1, uint * param_2)
 * Address ranges: 00426ca4-00426cef
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00426ca4(int *param_1,uint *param_2)

{
  bool bVar1;
  undefined1 in_ZF;
  
  FUN_00403ee0((uint *)param_1[2],(uint *)param_1[0x15]);
  if (((bool)in_ZF) && ((param_1[1] == 0 || ((*(byte *)(param_1[1] + 0x20) & 1) == 0)))) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  FUN_00414cdc(param_1,param_2);
  if ((bVar1) && (*(int *)(param_1[0x10] + 8) == 0)) {
    FUN_004269c0(param_1,param_2);
  }
  return;
}

