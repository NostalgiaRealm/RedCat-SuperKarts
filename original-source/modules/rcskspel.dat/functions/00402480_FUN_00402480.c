/*
 * FUN_00402480 at 00402480
 * undefined FUN_00402480(void)
 * Address ranges: 00402480-004024cc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00402480(void)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  
  bVar1 = false;
  iVar3 = 0;
  piVar2 = &DAT_00503ef0;
  do {
    if (*piVar2 != -1) {
      FUN_004024d0(iVar3);
      if ((DAT_00508610 <= iVar3) && (!bVar1)) {
        if (DAT_0053b9e8 != 0) {
          FUN_00412ca0();
        }
        bVar1 = true;
      }
    }
    piVar2 = piVar2 + 0x47;
    iVar3 = iVar3 + 1;
  } while ((int)piVar2 < 0x504f94);
  return;
}

