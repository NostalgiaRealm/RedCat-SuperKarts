/*
 * FUN_00455a10 at 00455a10
 * undefined FUN_00455a10(void)
 * Address ranges: 00455a10-00455af9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00455a10(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  float10 fVar4;
  
  fVar4 = (float10)FUN_0048f4e0();
  *(float *)(param_1 + 0x1c) = (float)(fVar4 + (float10)*(float *)(param_1 + 0x1c));
  iVar2 = FUN_0044fb40();
  if (iVar2 != 1) {
    cVar1 = FUN_0044fc00();
    if (cVar1 == '\0') {
      iVar2 = FUN_004500d0();
      iVar2 = DAT_006a5c38 + *(int *)(iVar2 * 0xd0 + DAT_0067ee20 + 0xc) * 0xa9;
      uVar3 = FUN_004500d0();
      fVar4 = (float10)FUN_00430ff0(uVar3);
      *(float *)(iVar2 + 0x54) = (float)fVar4;
    }
    else {
      FUN_00455ce0();
    }
    FUN_004500c0();
    FUN_004a09e0();
    iVar2 = 0;
    if (-1 < DAT_00508610) {
      while( true ) {
        cVar1 = FUN_0044fc80(iVar2);
        if ((cVar1 != '\0') &&
           ((iVar2 != *(int *)(param_1 + 0x20) || (_DAT_00544a80 < *(float *)(param_1 + 0x1c)))))
        break;
        iVar2 = iVar2 + 1;
        if (DAT_00508610 < iVar2) {
          return;
        }
      }
      FUN_00455b00(iVar2);
    }
  }
  return;
}

