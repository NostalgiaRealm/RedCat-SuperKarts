/*
 * FUN_00417e30 at 00417e30
 * undefined FUN_00417e30(void)
 * Address ranges: 00417e30-00417e89
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00417e30(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar4 = 0;
  if (0 < DAT_00508610) {
    puVar5 = &DAT_005081b4;
    do {
      cVar1 = FUN_00417e90(iVar4);
      iVar2 = DAT_0053be28;
      if (cVar1 == '\0') {
        iVar2 = puVar5[2];
      }
      if (iVar2 == param_1) {
        uVar3 = FUN_0042a4d0(iVar4 + 9);
        *puVar5 = uVar3;
        FUN_0042a280(iVar4 + 9);
        puVar5[3] = 1;
      }
      iVar4 = iVar4 + 1;
      puVar5 = puVar5 + 0x1c;
    } while (iVar4 < DAT_00508610);
  }
  return;
}

