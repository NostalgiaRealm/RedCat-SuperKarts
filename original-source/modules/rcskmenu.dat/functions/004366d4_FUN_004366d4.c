/*
 * FUN_004366d4 at 004366d4
 * undefined __register FUN_004366d4(int param_1, int param_2, byte param_3)
 * Address ranges: 004366d4-00436733
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004366d4(int param_1,int param_2,byte param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_00438084(param_1);
  if (-1 < iVar1 + -1) {
    iVar3 = 0;
    do {
      if (iVar3 < param_2) {
        iVar2 = FUN_00438094(param_1,iVar3);
        if (param_3 < *(byte *)(iVar2 + 0x33)) {
          FUN_004358cc((undefined4 *)PTR_PTR_0047c680);
        }
      }
      else {
        iVar2 = FUN_00438094(param_1,iVar3);
        if (*(byte *)(iVar2 + 0x33) < param_3) {
          iVar2 = FUN_00438094(param_1,iVar3);
          *(byte *)(iVar2 + 0x33) = param_3;
        }
      }
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}

