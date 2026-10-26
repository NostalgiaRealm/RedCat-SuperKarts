/*
 * FUN_004b4d70 at 004b4d70
 * undefined FUN_004b4d70(void)
 * Address ranges: 004b4d70-004b4f9d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004b4d70(char *param_1,uint param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  char *pcVar10;
  
  if (DAT_006ab7b4 == 0) {
    return -1;
  }
  iVar3 = FUN_004b4240(param_1,0,0,0);
  if (iVar3 == -1) {
    iVar4 = FUN_004b42b0(0);
    if (iVar4 == -1) {
      iVar4 = FUN_004b4310(0xffffffff);
    }
    FUN_004afce0(s_new_buffer_used__d_00500ae0,iVar4);
    iVar3 = FUN_004b4be0(param_1,iVar4);
    if (iVar3 != 0) {
      return -1;
    }
    *(undefined4 *)(iVar4 * 0x44 + 0x30 + DAT_006ab798) = 1;
    uVar7 = 0xffffffff;
    pcVar9 = param_1;
    do {
      pcVar10 = pcVar9;
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      pcVar10 = pcVar9 + 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar10;
    } while (cVar1 != '\0');
    uVar7 = ~uVar7;
    pcVar9 = pcVar10 + -uVar7;
    pcVar10 = (char *)(DAT_006ab798 + iVar4 * 0x44);
    for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
      *(undefined4 *)pcVar10 = *(undefined4 *)pcVar9;
      pcVar9 = pcVar9 + 4;
      pcVar10 = pcVar10 + 4;
    }
    for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *pcVar10 = *pcVar9;
      pcVar9 = pcVar9 + 1;
      pcVar10 = pcVar10 + 1;
    }
  }
  else {
    iVar5 = FUN_004b3f30(iVar3);
    iVar4 = iVar3;
    if ((iVar5 != 0) && (iVar4 = FUN_004b4240(param_1,0,iVar3 + 1,1), iVar4 == -1)) {
      iVar4 = FUN_004b42b0(0);
      if (iVar4 == -1) {
        iVar4 = FUN_004b4310(iVar3);
      }
      if (iVar4 == iVar3) {
        FUN_004afee0(s__s__d____duplicate_buffers_00500ac0,s_C__libraries_dxdraw_Sound_cpp_00500494,
                     0x5a2);
      }
      FUN_004afce0(s_duplicate_used__d_00500aac,iVar4);
      iVar5 = iVar4 * 0x44;
      *(undefined4 *)(iVar5 + 0x30 + DAT_006ab798) = 1;
      uVar7 = 0xffffffff;
      pcVar9 = param_1;
      do {
        pcVar10 = pcVar9;
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        pcVar10 = pcVar9 + 1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar10;
      } while (cVar1 != '\0');
      uVar7 = ~uVar7;
      pcVar9 = pcVar10 + -uVar7;
      pcVar10 = (char *)(DAT_006ab798 + iVar5);
      for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar9;
        pcVar9 = pcVar9 + 4;
        pcVar10 = pcVar10 + 4;
      }
      for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *pcVar10 = *pcVar9;
        pcVar9 = pcVar9 + 1;
        pcVar10 = pcVar10 + 1;
      }
      uVar6 = FUN_004b3ef0(*(undefined4 *)(DAT_006ab798 + 0x28 + iVar3 * 0x44));
      *(undefined4 *)(iVar5 + 0x28 + DAT_006ab798) = uVar6;
    }
  }
  if ((param_2 & 4) == 0) {
    *(undefined4 *)(iVar4 * 0x44 + 0x38 + DAT_006ab798) = DAT_006ab78c;
  }
  else {
    param_2 = param_2 - 4;
    *(undefined4 *)(iVar4 * 0x44 + 0x38 + DAT_006ab798) = 1000000;
  }
  iVar3 = FUN_004b3f30(iVar4);
  if ((iVar3 == 0) &&
     (piVar2 = *(int **)(iVar4 * 0x44 + 0x28 + DAT_006ab798),
     iVar3 = (**(code **)(*piVar2 + 0x30))(piVar2,0,0,param_2), iVar3 != 0)) {
    uVar6 = FUN_004b3910(iVar3);
    FUN_004afee0(s__s__d____error_playing_sound__d___00500a6c,
                 s_C__libraries_dxdraw_Sound_cpp_00500494,0x5b6,iVar4,uVar6);
  }
  FUN_004afce0(s_playing__s_buffer__d_00500a94,param_1,iVar4);
  return iVar4;
}

