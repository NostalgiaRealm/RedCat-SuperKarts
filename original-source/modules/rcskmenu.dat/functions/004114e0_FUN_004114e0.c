/*
 * FUN_004114e0 at 004114e0
 * undefined1 __register FUN_004114e0(int param_1, undefined * param_2, uint * param_3)
 * Address ranges: 004114e0-00411544
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 FUN_004114e0(int param_1,undefined *param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined1 local_14;
  
  local_14 = 0;
  uVar3 = 0;
  iVar4 = *(int *)(param_1 + 0x10) + -1;
  if (-1 < iVar4) {
    do {
      uVar2 = iVar4 + uVar3 >> 1;
      iVar1 = FUN_00407db0(*(undefined **)(*(int *)(param_1 + 0xc) + uVar2 * 8),param_2);
      if (iVar1 < 0) {
        uVar3 = uVar2 + 1;
      }
      else {
        iVar4 = uVar2 - 1;
        if ((iVar1 == 0) && (local_14 = 1, *(char *)(param_1 + 0x19) != '\x01')) {
          uVar3 = uVar2;
        }
      }
    } while ((int)uVar3 <= iVar4);
  }
  *param_3 = uVar3;
  return local_14;
}

