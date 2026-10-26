/*
 * FUN_0041e680 at 0041e680
 * undefined4 __stdcall FUN_0041e680(void)
 * Address ranges: 0041e680-0041e6ef
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0041e680(void)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint *puVar5;
  int iVar6;
  
  iVar6 = 0;
  if (DAT_0043e210 != 0) {
    puVar5 = (uint *)&DAT_0043e210;
    do {
      iVar3 = FUN_004133f0(*puVar5);
      if (iVar3 != 0) {
        uVar2 = (&DAT_0043e210)[iVar6 * 2];
        if (uVar2 == 0) {
          return 0;
        }
        iVar6 = FUN_004133f0(uVar2);
        while (iVar6 != 0) {
          FUN_0040a97d();
          iVar6 = FUN_004133f0(uVar2);
        }
        uVar4 = FUN_0041e6f0(uVar2);
        return uVar4;
      }
      puVar1 = puVar5 + 2;
      puVar5 = puVar5 + 2;
      iVar6 = iVar6 + 1;
    } while (*puVar1 != 0);
  }
  return 0;
}

