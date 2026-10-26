/*
 * FUN_004a5410 at 004a5410
 * undefined FUN_004a5410(void)
 * Address ranges: 004a5410-004a57fd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004a5410(char *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  
  FUN_004afce0(s_adding_anim___s__frames__d_004fceb4,param_1,param_2);
  FUN_004a6f20();
  iVar8 = DAT_006a5f80;
  if (DAT_006a5f84 == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_new__s__d__004de824,s___array_hpp_004fc894,0xb9,
                 &DAT_006a5f8c,DAT_006a5f7c,&DAT_006a5fa5);
    iVar8 = DAT_006a5f80;
  }
  for (; iVar8 < DAT_006a5f7c; iVar8 = iVar8 + 1) {
    if (*(char *)(DAT_006a5f88 + iVar8) == '\0') goto LAB_004a57cc;
  }
  iVar8 = 0;
  if (0 < DAT_006a5f80) {
    do {
      if (*(char *)(DAT_006a5f88 + iVar8) == '\0') goto LAB_004a57cc;
      iVar8 = iVar8 + 1;
    } while (iVar8 < DAT_006a5f80);
  }
  FUN_004afee0(s__s__d____T_ARRAY__new_array__s_0_004de7d8,s___array_hpp_004fc894,0xce,&DAT_006a5f8c
               ,DAT_006a5f7c,&DAT_006a5fa5);
  iVar8 = -1;
LAB_004a54ca:
  FUN_004afce0(s___anim_index__d_004fcea0,iVar8);
  if (DAT_006a5f84 == 0) {
    FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1b1,
                 &DAT_006a5f8c,DAT_006a5f7c,&DAT_006a5fa5);
  }
  if ((iVar8 < 0) || (DAT_006a5f7c <= iVar8)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1b5,
                 &DAT_006a5f8c,iVar8,DAT_006a5f7c);
  }
  if (*(char *)(DAT_006a5f88 + iVar8) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1b9,
                 &DAT_006a5f8c,iVar8);
  }
  iVar2 = iVar8 * 9;
  *(int *)(iVar2 + DAT_006a5f78) = param_2;
  FUN_004afce0(s___allocate_memory_for_frame_indi_004fce78);
  if (DAT_006a5f84 == 0) {
    FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1b1,
                 &DAT_006a5f8c,DAT_006a5f7c,&DAT_006a5fa5);
  }
  if ((iVar8 < 0) || (DAT_006a5f7c <= iVar8)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1b5,
                 &DAT_006a5f8c,iVar8,DAT_006a5f7c);
  }
  if (*(char *)(DAT_006a5f88 + iVar8) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1b9,
                 &DAT_006a5f8c,iVar8);
  }
  pvVar3 = _malloc(param_2 * 4);
  *(void **)(iVar2 + 4 + DAT_006a5f78) = pvVar3;
  if (pvVar3 == (void *)0x0) {
    FUN_004afee0(s__s__d__not_enough_memory_to_allo_004fce14,
                 s_D__work_libs_DX3D_Animsys_cpp_004fce58,0x7c,iVar8);
  }
  if (DAT_006a5f84 == 0) {
    FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1b1,
                 &DAT_006a5f8c,DAT_006a5f7c,&DAT_006a5fa5);
  }
  if ((iVar8 < 0) || (DAT_006a5f7c <= iVar8)) {
    FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1b5,
                 &DAT_006a5f8c,iVar8,DAT_006a5f7c);
  }
  if (*(char *)(DAT_006a5f88 + iVar8) == '\0') {
    FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1b9,
                 &DAT_006a5f8c,iVar8);
  }
  iVar9 = 0;
  *(undefined1 *)(iVar2 + 8 + DAT_006a5f78) = 0;
  if (0 < param_2) {
    do {
      if (DAT_006a5f84 == 0) {
        FUN_004afee0(s__s__d____T_ARRAY______s__d__of_t_004fc858,s___array_hpp_004fc894,0x1b1,
                     &DAT_006a5f8c,DAT_006a5f7c,&DAT_006a5fa5);
      }
      if ((iVar8 < 0) || (DAT_006a5f7c <= iVar8)) {
        FUN_004afee0(s__s__d____out_of_boundaries__s__d_004fc818,s___array_hpp_004fc894,0x1b5,
                     &DAT_006a5f8c,iVar8,DAT_006a5f7c);
      }
      if (*(char *)(DAT_006a5f88 + iVar8) == '\0') {
        FUN_004afee0(s__s__d____array_element_not_regis_004fc7e8,s___array_hpp_004fc894,0x1b9,
                     &DAT_006a5f8c,iVar8);
      }
      iVar9 = iVar9 + 1;
      *(undefined4 *)(*(int *)(iVar2 + 4 + DAT_006a5f78) + -4 + iVar9 * 4) = 0xffffffff;
    } while (iVar9 < param_2);
  }
  FUN_004afce0(s___add_name_to_list_004fcdfc);
  uVar4 = FUN_004a71f0();
  uVar6 = 0xffffffff;
  pcVar5 = param_1;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  if (0x18 < ~uVar6 - 1) {
    FUN_004afee0(s__s__d__anim_name_is_to_long_max___004fcdd4,
                 s_D__work_libs_DX3D_Animsys_cpp_004fce58,0x92,0x19);
    return iVar8;
  }
  pcVar5 = (char *)FUN_004a7280(uVar4);
  uVar6 = 0xffffffff;
  do {
    pcVar10 = param_1;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar10 = param_1 + 1;
    cVar1 = *param_1;
    param_1 = pcVar10;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  pcVar10 = pcVar10 + -uVar6;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar10;
    pcVar10 = pcVar10 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar5 = *pcVar10;
    pcVar10 = pcVar10 + 1;
    pcVar5 = pcVar5 + 1;
  }
  return iVar8;
LAB_004a57cc:
  *(undefined1 *)(DAT_006a5f88 + iVar8) = 1;
  DAT_006a5f80 = iVar8;
  goto LAB_004a54ca;
}

