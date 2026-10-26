/*
 * FUN_0048d930 at 0048d930
 * undefined FUN_0048d930(void)
 * Address ranges: 0048d930-0048da32
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_0048d930(int param_1,int *param_2)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  if (*param_2 < 0) {
    *param_2 = (int)param_2;
    return 1;
  }
  uVar6 = 6;
  iVar5 = DAT_00680ae0;
  do {
    bVar1 = false;
    iVar3 = *param_2;
    uVar7 = uVar6;
    if (0 < (int)uVar6) {
      do {
        iVar3 = FUN_00404be0(iVar3,0);
        uVar7 = uVar7 - 1;
        iVar5 = DAT_00680ae0;
      } while (uVar7 != 0);
    }
    iVar4 = iVar3 * 0x50 + iVar5;
    if ((iVar3 == -1) || (*(int *)(iVar4 + 0x24) != 0)) {
      bVar1 = true;
    }
    if (((*(int *)(iVar4 + 0x14) != -1) && (!bVar1)) &&
       (*(int *)(*(int *)(iVar4 + 0x14) * 0x50 + 0x24 + iVar5) != 0)) {
      bVar1 = true;
    }
    if (*(int *)(iVar4 + 0x20) == -1) {
      if (!bVar1) goto LAB_0048d9c2;
    }
    else if ((!bVar1) && (*(int *)(*(int *)(iVar4 + 0x20) * 0x50 + 0x24 + iVar5) == 0)) {
LAB_0048d9c2:
      cVar2 = FUN_0048c170(*(undefined4 *)(param_1 + 0x1180),*(undefined4 *)(iVar4 + 8),
                           *(undefined4 *)(iVar4 + 0xc),*(undefined4 *)(iVar4 + 0x10));
      iVar5 = DAT_00680ae0;
      if (cVar2 != '\0') {
        *param_2 = iVar3;
        return 1;
      }
    }
    uVar6 = uVar6 - 1;
    if (0x7fffffff < uVar6) {
      *param_2 = iVar3;
      return 1;
    }
  } while( true );
}

