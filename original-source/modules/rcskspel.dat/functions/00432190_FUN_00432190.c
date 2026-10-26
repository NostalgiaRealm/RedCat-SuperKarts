/*
 * FUN_00432190 at 00432190
 * undefined FUN_00432190(void)
 * Address ranges: 00432190-0043223b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00432190(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = FUN_00429050();
  if (iVar2 != 0) {
    FUN_0049dd20(DAT_0053badc);
    if ((DAT_004e0d14 == '\0') || (DAT_0050728c < 4)) {
      iVar2 = FUN_0049d870();
      if (iVar2 != 0) {
        FUN_0049dd20(DAT_0053badc);
        FUN_0049d7a0();
      }
    }
    else {
      iVar2 = DAT_0050728c * 4 + -0x10;
      iVar3 = FUN_0049d870();
      if (iVar3 != 0) {
        FUN_0049d5e0(iVar2);
        return;
      }
      FUN_004371f0();
      cVar1 = FUN_00437550();
      if (cVar1 != '\0') {
        uVar4 = 1;
        FUN_0049dd20(DAT_0053badc);
        FUN_0049d780(uVar4);
        FUN_0049d5e0(iVar2);
        return;
      }
    }
  }
  return;
}

