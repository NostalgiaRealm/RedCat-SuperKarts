/*
 * FUN_00449228 at 00449228
 * undefined4 __register FUN_00449228(int param_1, int param_2)
 * Address ranges: 00449228-004492a3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00449228(int param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_EBX;
  undefined4 uVar2;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  undefined3 uVar3;
  
  uVar3 = (undefined3)((uint)unaff_EBX >> 8);
  uVar2 = CONCAT31(uVar3,4);
  if (param_2 != 0) {
    FUN_0043f054(param_1,&local_14);
    FUN_0043f054(param_2,&local_24);
    if (((local_20 < local_10) || (local_18 <= local_8)) || (local_c < local_1c)) {
      if (((local_24 < local_14) || (local_1c <= local_c)) || (local_8 < local_18)) {
        iVar1 = local_20 + local_18 >> 1;
        if (iVar1 < 0) {
          iVar1 = iVar1 + (uint)((local_20 + local_18 & 1U) != 0);
        }
        if (iVar1 <= local_10) {
          uVar2 = CONCAT31(uVar3,2);
        }
      }
      else {
        uVar2 = CONCAT31(uVar3,3);
      }
    }
    else {
      uVar2 = CONCAT31(uVar3,1);
    }
  }
  return uVar2;
}

