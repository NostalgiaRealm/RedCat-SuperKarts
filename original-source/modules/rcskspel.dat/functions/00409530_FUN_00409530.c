/*
 * FUN_00409530 at 00409530
 * undefined FUN_00409530(void)
 * Address ranges: 00409530-0040969c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00409530(int param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  
  iVar4 = DAT_0067ee20;
  iVar5 = param_1 * 0x11c;
  if (*(int *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0x1c + DAT_0067ee20) ==
      *(int *)(&DAT_00503f14 + iVar5)) {
    fVar6 = (float10)FUN_0048f4e0();
    *(float *)(&DAT_00503f08 + iVar5) = (float)(fVar6 + (float10)*(float *)(&DAT_00503f08 + iVar5));
  }
  else {
    *(int *)(&DAT_00503f18 + iVar5) = *(int *)(&DAT_00503f14 + iVar5);
    iVar2 = DAT_00508610;
    *(undefined4 *)(&DAT_00503f14 + iVar5) =
         *(undefined4 *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0x1c + iVar4);
    *(undefined4 *)(&DAT_00503f08 + iVar5) = 0;
    if (param_1 < iVar2) {
      iVar4 = FUN_00404eb0(*(undefined4 *)(&DAT_00503f14 + iVar5),
                           *(undefined4 *)(&DAT_00503f18 + iVar5));
      if (iVar4 != 1) {
        cVar3 = FUN_00417e90(param_1);
        iVar4 = DAT_0053be28;
        if (cVar3 == '\0') {
          iVar4 = (&DAT_005081bc)[param_1 * 0x1c];
        }
        piVar1 = (int *)(DAT_00504f98 + 0x60 + *(int *)(iVar4 * 0xd0 + 0x10 + DAT_0067ee20) * 0x6c);
        iVar4 = FUN_00493a40(*(undefined4 *)(&DAT_00503f18 + iVar5),
                             *(undefined4 *)(&DAT_00503f14 + iVar5));
        *piVar1 = *piVar1 - iVar4;
        return;
      }
      cVar3 = FUN_00417e90(param_1);
      iVar4 = DAT_0053be28;
      if (cVar3 == '\0') {
        iVar4 = (&DAT_005081bc)[param_1 * 0x1c];
      }
      piVar1 = (int *)(DAT_00504f98 + 0x60 + *(int *)(iVar4 * 0xd0 + 0x10 + DAT_0067ee20) * 0x6c);
      iVar4 = FUN_00493a40(*(undefined4 *)(&DAT_00503f18 + iVar5),
                           *(undefined4 *)(&DAT_00503f14 + iVar5));
      *piVar1 = *piVar1 + iVar4;
      return;
    }
  }
  return;
}

