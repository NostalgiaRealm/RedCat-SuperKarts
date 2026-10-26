/*
 * FUN_0040cde0 at 0040cde0
 * undefined FUN_0040cde0(void)
 * Address ranges: 0040cde0-0040d06f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0040cde0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  FUN_00451450();
  iVar2 = param_1;
  cVar3 = FUN_00452370(param_1);
  if (cVar3 == '\0') {
    cVar3 = FUN_004523d0(iVar2);
    if (cVar3 == '\0') {
      FUN_00452120(iVar2);
      iVar4 = FUN_0044ff80();
      if (iVar4 == 2) {
        FUN_00452120(iVar2);
        iVar4 = FUN_004500b0();
        if (iVar4 == 5) {
          FUN_0040d980(iVar2);
          return 1;
        }
      }
    }
    else {
      iVar4 = DAT_0053be28 * 0xd0 + DAT_0067ee20;
      puVar1 = (undefined4 *)(*(int *)(iVar4 + 0x24) * 0x50 + 8 + DAT_00680ae0);
      uStack_c = *puVar1;
      uStack_8 = puVar1[1];
      uStack_4 = puVar1[2];
      iVar4 = FUN_00493a40(*(undefined4 *)
                            ((&DAT_00503ef0)[iVar2 * 0x47] * 0xd0 + 0x1c + DAT_0067ee20),
                           *(undefined4 *)(iVar4 + 0x1c));
      iVar5 = FUN_00406320((&DAT_00503ef0)[iVar2 * 0x47],&uStack_c);
      if ((iVar5 != 0) && (iVar4 < 4)) {
        FUN_0040d980(iVar2);
        return 1;
      }
      fVar6 = (float10)FUN_0048f4d0();
      if ((float10)5.0 < fVar6 - (float10)*(float *)(&DAT_00504004 + iVar2 * 0x11c)) {
        FUN_0040d980(iVar2);
        return 1;
      }
      if (0x6f854 < DAT_0050592c) {
        FUN_0040d980(iVar2);
        DAT_0050592c = 0;
        return 1;
      }
      DAT_0050592c = DAT_0050592c + 1;
    }
  }
  else {
    cVar3 = FUN_00417e90((&DAT_00503ef0)[iVar2 * 0x47]);
    iVar4 = DAT_0053be60;
    if (cVar3 == '\0') {
      iVar4 = (&DAT_005081b8)[(&DAT_00503ef0)[iVar2 * 0x47] * 0x1c];
    }
    if (iVar4 != 0) {
      param_1 = 0;
      iVar4 = FUN_00410420((&DAT_00503ef0)[iVar2 * 0x47],2,&param_1);
      if (iVar4 != -1) {
        if (iVar4 == DAT_0053be28) {
          FUN_00435a30();
          cVar3 = FUN_004362e0();
          if (cVar3 == '\0') {
            FUN_00452120(iVar2);
            iVar4 = FUN_004500b0();
            if (iVar4 == 1) {
              FUN_0040d980(iVar2);
              return 1;
            }
            if (param_1 < 0x14) {
              FUN_0040d980(iVar2);
              return 1;
            }
          }
        }
        else {
          fVar6 = (float10)FUN_0048f4d0();
          if ((float10)10.0 < fVar6 - (float10)*(float *)(&DAT_00504004 + iVar2 * 0x11c)) {
            FUN_0040d980(iVar2);
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

