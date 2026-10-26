/*
 * FUN_00485120 at 00485120
 * undefined FUN_00485120(void)
 * Address ranges: 00485120-004851b1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00485120(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  uVar3 = (uVar1 >> 0x10 & 0xff) + 0x2d;
  if (0xff < uVar3) {
    uVar3 = 0;
  }
  uVar7 = (uVar1 >> 8 & 0xff) + 0x41;
  if (0xff < uVar7) {
    uVar7 = 0;
  }
  uVar5 = (uVar1 & 0xff) + 0x55;
  if (0xff < uVar5) {
    uVar5 = 0;
  }
  iVar2 = (uVar1 >> 0x18) - 0x14;
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x154)) {
    puVar6 = (undefined4 *)(param_1 + 0x14);
    do {
      puVar6[-1] = ((iVar2 << 8 | uVar3) << 8 | uVar7) << 8 | uVar5;
      *puVar6 = 0;
      iVar4 = iVar4 + 1;
      puVar6 = puVar6 + 8;
    } while (iVar4 < *(int *)(param_1 + 0x154));
  }
  return;
}

