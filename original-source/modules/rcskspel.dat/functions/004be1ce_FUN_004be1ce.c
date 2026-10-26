/*
 * FUN_004be1ce at 004be1ce
 * undefined FUN_004be1ce(void)
 * Address ranges: 004be1ce-004be286
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_004be1ce(void)

{
  void *pvVar1;
  size_t sVar2;
  int iVar3;
  int unaff_EBP;
  
  FUN_004c0dec();
  iVar3 = DAT_006b6690;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (iVar3 == 0) {
    pvVar1 = operator_new(0x28);
    *(void **)(unaff_EBP + -0x10) = pvVar1;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    if (pvVar1 == (void *)0x0) {
      DAT_006b6690 = 0;
    }
    else {
      DAT_006b6690 = FUN_004be2cf(0);
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_004be654(FUN_004be287);
    *(undefined4 *)(DAT_006b6690 + 0x10) = 0x3f;
    sVar2 = _strlen("C");
    FUN_0040b540(&DAT_004d36c4,sVar2);
    DAT_006b668c = DAT_006b6690;
    if (*(int *)(DAT_006b6690 + 4) != -1) {
      *(int *)(DAT_006b6690 + 4) = *(int *)(DAT_006b6690 + 4) + 1;
    }
    _DAT_006b6688 = DAT_006b668c;
    iVar3 = DAT_006b6690;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar3;
}

