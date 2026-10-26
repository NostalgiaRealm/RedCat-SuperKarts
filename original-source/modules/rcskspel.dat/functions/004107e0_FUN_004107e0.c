/*
 * FUN_004107e0 at 004107e0
 * undefined FUN_004107e0(void)
 * Address ranges: 004107e0-004108eb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004107e0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int local_c;
  int local_8;
  undefined1 local_4 [4];
  
  iVar4 = param_1;
  iVar6 = DAT_00680220 / 2;
  iVar5 = FUN_00497b30(*(undefined4 *)(param_1 * 0xd0 + 0x1c + DAT_0067ee20),DAT_0053b9d0 + -1,
                       &param_1,&local_8,local_4,&local_c);
  piVar7 = &DAT_0050738c;
  do {
    if ((piVar7[-1] == 0) || (iVar1 = *piVar7, iVar1 == iVar4)) goto LAB_004108d5;
    iVar2 = *(int *)(iVar1 * 0xd0 + 0x1c + DAT_0067ee20);
    iVar3 = param_1;
    if (iVar5 == 0) {
      if (iVar2 < param_1) {
        iVar2 = piVar7[1];
        iVar3 = local_8;
      }
      else {
        if (iVar2 <= local_8) goto LAB_004108d5;
        iVar2 = piVar7[1];
      }
joined_r0x004108c0:
      if ((iVar2 != 3) && (iVar2 != 4)) {
        FUN_004108f0(iVar1,iVar3,0);
      }
    }
    else if (iVar2 < iVar6) {
      if (local_c < iVar2) {
        iVar2 = piVar7[1];
        goto joined_r0x004108c0;
      }
    }
    else if (iVar2 < param_1) {
      iVar2 = piVar7[1];
      iVar3 = local_c;
      goto joined_r0x004108c0;
    }
LAB_004108d5:
    piVar7 = piVar7 + 3;
    if (0x507f43 < (int)piVar7) {
      return;
    }
  } while( true );
}

