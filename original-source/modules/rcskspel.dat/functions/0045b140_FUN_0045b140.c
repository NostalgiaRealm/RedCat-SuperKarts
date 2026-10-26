/*
 * FUN_0045b140 at 0045b140
 * undefined FUN_0045b140(void)
 * Address ranges: 0045b140-0045b167
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0045b140(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(param_1 + 0x308);
  iVar2 = 0x1a;
  do {
    if (*piVar1 == -1) {
      *piVar1 = piVar1[-0x40];
      piVar1[1] = piVar1[-0x3f];
    }
    piVar1 = piVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

