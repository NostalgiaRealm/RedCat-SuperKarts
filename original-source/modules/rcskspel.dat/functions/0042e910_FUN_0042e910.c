/*
 * FUN_0042e910 at 0042e910
 * undefined FUN_0042e910(void)
 * Address ranges: 0042e910-0042e967
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042e910(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  
  uVar6 = 0;
  uVar2 = DAT_0053be28;
  FUN_0048e210(0,DAT_0053be28);
  FUN_0048e540(uVar6,uVar2);
  iVar3 = 0;
  if (0 < DAT_00508610) {
    puVar4 = &DAT_005081bc;
    do {
      cVar1 = FUN_00417e90(iVar3);
      uVar2 = DAT_0053be28;
      if (cVar1 == '\0') {
        uVar2 = *puVar4;
      }
      iVar3 = iVar3 + 1;
      iVar5 = iVar3;
      FUN_0048e210(iVar3,uVar2);
      FUN_0048e540(iVar5,uVar2);
      puVar4 = puVar4 + 0x1c;
    } while (iVar3 < DAT_00508610);
  }
  return;
}

