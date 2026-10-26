/*
 * FUN_004b51e0 at 004b51e0
 * undefined FUN_004b51e0(void)
 * Address ranges: 004b51e0-004b53a1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004b51e0(char *param_1,byte param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  char *pcVar9;
  
  if (DAT_006ab7b4 == 0) {
    return -1;
  }
  iVar2 = FUN_004b4240(param_1,0,0,0);
  if (iVar2 == -1) {
    iVar3 = FUN_004b42b0(0);
    if (iVar3 == -1) {
      iVar3 = FUN_004b4310(0xffffffff);
    }
    FUN_004afce0(s_new_buffer_used__d_00500ae0,iVar3);
    iVar2 = FUN_004b4be0(param_1,iVar3);
    if (iVar2 != 0) {
      return -1;
    }
    *(undefined4 *)(iVar3 * 0x44 + 0x30 + DAT_006ab798) = 1;
    uVar6 = 0xffffffff;
    do {
      pcVar8 = param_1;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar8 = param_1 + 1;
      cVar1 = *param_1;
      param_1 = pcVar8;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    pcVar8 = pcVar8 + -uVar6;
    pcVar9 = (char *)(DAT_006ab798 + iVar3 * 0x44);
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar9 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar9 = pcVar9 + 1;
    }
  }
  else {
    iVar4 = FUN_004b3f30(iVar2);
    iVar3 = iVar2;
    if ((iVar4 != 0) && (iVar3 = FUN_004b4240(param_1,0,iVar2 + 1,1), iVar3 == -1)) {
      iVar3 = FUN_004b42b0(0);
      if (iVar3 == -1) {
        iVar3 = FUN_004b4310(iVar2);
      }
      if (iVar3 == iVar2) {
        FUN_004afee0(s__s__d____duplicate_buffers_00500ac0,s_C__libraries_dxdraw_Sound_cpp_00500494,
                     0x644);
      }
      FUN_004afce0(s_duplicate_used__d_00500aac,iVar3);
      iVar4 = iVar3 * 0x44;
      *(undefined4 *)(DAT_006ab798 + 0x30 + iVar4) = 1;
      uVar6 = 0xffffffff;
      do {
        pcVar8 = param_1;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar8 = param_1 + 1;
        cVar1 = *param_1;
        param_1 = pcVar8;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      pcVar8 = pcVar8 + -uVar6;
      pcVar9 = (char *)(DAT_006ab798 + iVar4);
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar9 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar9 = pcVar9 + 1;
      }
      uVar5 = FUN_004b3ef0(*(undefined4 *)(DAT_006ab798 + 0x28 + iVar2 * 0x44));
      *(undefined4 *)(DAT_006ab798 + 0x28 + iVar4) = uVar5;
    }
  }
  if ((param_2 & 4) == 0) {
    *(undefined4 *)(DAT_006ab798 + 0x38 + iVar3 * 0x44) = DAT_006ab78c;
    return iVar3;
  }
  *(undefined4 *)(DAT_006ab798 + 0x38 + iVar3 * 0x44) = 1000000;
  return iVar3;
}

