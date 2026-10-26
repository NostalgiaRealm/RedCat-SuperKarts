/*
 * FUN_0041b120 at 0041b120
 * undefined FUN_0041b120(void)
 * Address ranges: 0041b120-0041b234
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041b120(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  FUN_0041b0d0();
  FUN_004b1850(0,0,0x28,&DAT_004e2580);
  iVar1 = FUN_004b3830(0x1b);
  while (iVar1 == 0) {
    iVar1 = FUN_004b3830(0x22);
    if (iVar1 != 0) {
      DAT_004e17d4 = DAT_004e17d4 + -1;
      if (DAT_004e17d4 < 0) {
        DAT_004e17d4 = 0;
      }
      FUN_00419230(0x22);
      FUN_004b1850(0,200,0x28,&DAT_004e2584,DAT_004e17d4);
    }
    iVar1 = FUN_004b3830(0x21);
    if (iVar1 != 0) {
      DAT_004e17d4 = DAT_004e17d4 + 1;
      if (9 < DAT_004e17d4) {
        DAT_004e17d4 = 9;
      }
      FUN_00419230(0x21);
      FUN_004b1850(0,200,0x28,&DAT_004e2588,DAT_004e17d4);
    }
    iVar1 = FUN_004b3830(0x7b);
    if (iVar1 != 0) {
      puVar2 = (undefined4 *)(&DAT_005068d0 + DAT_00508618 * 0x7c);
      puVar3 = (undefined4 *)(&DAT_005068d0 + DAT_004e17d4 * 0x7c);
      for (iVar1 = 0x1f; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    iVar1 = FUN_004b3830(0x1b);
  }
  FUN_00419230(0x1b);
  return;
}

