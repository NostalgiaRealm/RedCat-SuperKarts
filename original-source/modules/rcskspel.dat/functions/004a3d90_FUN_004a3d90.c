/*
 * FUN_004a3d90 at 004a3d90
 * undefined FUN_004a3d90(void)
 * Address ranges: 004a3d90-004a41b7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_004a3d90(int param_1,int param_2,int param_3)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  char **ppcVar7;
  char *pcStack_3c;
  int *piStack_38;
  int *piStack_34;
  int *piStack_30;
  char *pcStack_2c;
  int *piStack_28;
  char *pcStack_24;
  int *piStack_20;
  int local_c;
  undefined1 auStack_8 [8];
  
  iVar6 = param_2;
  piStack_20 = (int *)param_2;
  pcStack_24 = (char *)0x4a3da6;
  FUN_004ad120();
  *(int *)(param_1 + 0x2c) = param_3;
  piStack_20 = (int *)0x4a3db2;
  puVar2 = (undefined4 *)FUN_004ae4a0();
  ppcVar7 = &pcStack_3c;
  for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
    *ppcVar7 = (char *)*puVar2;
    puVar2 = puVar2 + 1;
    ppcVar7 = ppcVar7 + 1;
  }
  FUN_004b5c20();
  uVar3 = FUN_004ae4a0();
  uVar3 = FUN_004a3c50(iVar6,&local_c,&param_2,0x1800,uVar3);
  *(undefined4 *)(param_1 + 4) = uVar3;
  puVar2 = (undefined4 *)FUN_004ae4a0();
  ppcVar7 = &pcStack_3c;
  for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
    *ppcVar7 = (char *)*puVar2;
    puVar2 = puVar2 + 1;
    ppcVar7 = ppcVar7 + 1;
  }
  FUN_004b5c20();
  *(int *)(param_1 + 0x28) = param_2;
  *(int *)(param_1 + 0x24) = local_c;
  bVar1 = false;
LAB_004a3e13:
  do {
    piStack_20 = *(int **)(param_1 + 0x24);
    if ((piStack_20 != (int *)*(int *)(param_1 + 0x28)) && ((DAT_006a5ed8 != 0 || (bVar1)))) {
      pcStack_24 = (char *)0x4a3e39;
      iVar6 = FUN_004a1470();
      pcStack_24 = *(char **)(param_1 + 0x28);
      piStack_28 = (int *)0x4a3e44;
      iVar5 = FUN_004a1470();
      param_2 = 1 << ((byte)((iVar5 + iVar6) / 2) & 0x1f);
      *(int *)(param_1 + 0x24) = param_2;
      *(int *)(param_1 + 0x28) = param_2;
      piStack_28 = (int *)0x4a3e64;
      local_c = param_2;
      piStack_28 = (int *)FUN_004ae4a0();
      pcStack_2c = (char *)0x1800;
      piStack_30 = (int *)param_2;
      piStack_34 = (int *)local_c;
      piStack_38 = (int *)0x4a3e79;
      piVar4 = (int *)FUN_004b0a10();
      pcStack_2c = *(char **)(param_1 + 4);
      piStack_20 = (int *)0x0;
      pcStack_24 = (char *)0x1000000;
      piStack_28 = (int *)0x0;
      piStack_30 = (int *)0x0;
      piStack_38 = (int *)0x4a3e93;
      piStack_34 = piVar4;
      piStack_38 = (int *)(**(code **)(*piVar4 + 0x14))();
      if (piStack_38 != (int *)0x0) {
        pcStack_3c = "PhW\x01";
        pcStack_3c = (char *)FUN_004b0190();
        FUN_004afee0(s__s__d____blt_surf_2_surf_blittin_004fcc74,
                     s_D__work_libs_DX3D_text_cpp_004fca28,0x157);
      }
      piStack_38 = *(int **)(param_1 + 4);
      pcStack_3c = (char *)0x4a3ebe;
      (**(code **)(*piStack_38 + 8))();
      *(int **)(param_1 + 4) = piVar4;
    }
    piStack_28 = *(int **)(param_1 + 4);
    pcStack_24 = &DAT_004d40d0;
    pcStack_2c = (char *)0x4a3ed2;
    piStack_20 = (undefined4 *)(param_1 + 0xc);
    piStack_20 = (int *)(**(code **)*piStack_28)();
    if (piStack_20 != (int *)0x0) {
      if (piStack_20 == (int *)0x887602e2) {
        piStack_20 = (int *)0x4a3fb5;
        iVar6 = FUN_004ae830();
        if (iVar6 != 0) {
          bVar1 = true;
          goto LAB_004a3e13;
        }
      }
      else {
        pcStack_24 = "Phd\x01";
        pcStack_24 = (char *)FUN_004aaa00();
        piStack_28 = (int *)0x164;
        pcStack_2c = s_D__work_libs_DX3D_text_cpp_004fca28;
        piStack_30 = (int *)s__s__d____D3DError____s_004fcc58;
        piStack_34 = (int *)0x4a3efc;
        FUN_004afee0();
      }
    }
    piStack_20 = (int *)0x4a3f09;
    iVar6 = FUN_004ae830();
    if (iVar6 == 0) {
      piStack_20 = (int *)s________________NO_HAL____________004fcba8;
      pcStack_24 = (char *)0x4a3fce;
      FUN_004afce0();
      piStack_20 = *(int **)(param_1 + 4);
      *(int **)(param_1 + 8) = piStack_20;
      pcStack_24 = (char *)0x4a3fdd;
      (**(code **)(*piStack_20 + 4))();
      pcStack_24 = (char *)0x4a3fe2;
      iVar6 = FUN_004ae540();
      if (iVar6 == 2) {
        pcStack_24 = s_Setting_texture_palette_004fcb8c;
        piStack_28 = (int *)0x4a3ff1;
        FUN_004afce0();
        piStack_28 = *(int **)(param_1 + 4);
        pcStack_24 = (char *)DAT_006ab464;
        pcStack_2c = (char *)0x4a4004;
        pcStack_2c = (char *)(**(code **)(*piStack_28 + 0x7c))();
        if (pcStack_2c != (char *)0x0) {
          piStack_30 = (int *)0x4a400e;
          piStack_30 = (int *)FUN_004aaa00();
          piStack_34 = (int *)0x192;
          piStack_38 = (int *)s_D__work_libs_DX3D_text_cpp_004fca28;
          pcStack_3c = s__s__d____D3DError_setting_device_004fcb54;
          FUN_004afee0();
        }
        piStack_30 = *(int **)(param_1 + 8);
        pcStack_2c = (char *)DAT_006ab464;
        piStack_34 = (int *)0x4a4036;
        pcStack_24 = (char *)(**(code **)(*piStack_30 + 0x7c))();
        if (pcStack_24 != (char *)0x0) {
          piStack_28 = (int *)0x4a4040;
          piStack_28 = (int *)FUN_004aaa00();
          pcStack_2c = (char *)0x195;
          piStack_30 = (int *)s_D__work_libs_DX3D_text_cpp_004fca28;
          piStack_34 = (int *)s__s__d____D3DError_setting_device_004fcb54;
          piStack_38 = (int *)0x4a4055;
          FUN_004afee0();
        }
      }
      pcStack_2c = *(char **)(param_1 + 8);
      pcStack_24 = (char *)(param_1 + 0x10);
      piStack_28 = (int *)&DAT_004d40d0;
      piStack_30 = (int *)0x4a4069;
      piStack_20 = (int *)(*(code *)**(undefined4 **)pcStack_2c)();
      if (piStack_20 != (int *)0x0) {
        pcStack_24 = (char *)0x4a4073;
        pcStack_24 = (char *)FUN_004aaa00();
        piStack_28 = (int *)0x19c;
        pcStack_2c = s_D__work_libs_DX3D_text_cpp_004fca28;
        piStack_30 = (int *)s__s__d____D3DError_query_texture_i_004fcbf8;
        piStack_34 = (int *)0x4a4088;
        FUN_004afee0();
      }
    }
    else if (param_3 != 4) {
      piStack_20 = (int *)s________________HAL_EXISTS________004fcc2c;
      pcStack_24 = (char *)0x4a3f26;
      FUN_004afce0();
      pcStack_24 = (char *)0x4a3f2b;
      pcStack_24 = (char *)FUN_004ae4a0();
      piStack_28 = (int *)0x4005000;
      pcStack_2c = (char *)param_2;
      piStack_30 = (int *)local_c;
      piStack_34 = (int *)0x4a3f40;
      piStack_28 = (int *)FUN_004b0a10();
      *(int **)(param_1 + 8) = piStack_28;
      pcStack_24 = &DAT_004d40d0;
      pcStack_2c = (char *)0x4a3f54;
      piStack_20 = (undefined4 *)(param_1 + 0x10);
      pcStack_2c = (char *)(**(code **)*piStack_28)();
      if (pcStack_2c != (char *)0x0) {
        piStack_30 = (int *)0x4a3f5e;
        piStack_30 = (int *)FUN_004aaa00();
        piStack_34 = (int *)0x17b;
        piStack_38 = (int *)s_D__work_libs_DX3D_text_cpp_004fca28;
        pcStack_3c = s__s__d____D3DError_query_texture_i_004fcbf8;
        FUN_004afee0();
      }
      piStack_30 = *(int **)(param_1 + 0x10);
      pcStack_2c = *(char **)(param_1 + 0xc);
      piStack_34 = (int *)0x4a3f81;
      piStack_20 = (int *)(**(code **)(*piStack_30 + 0x14))();
      if (piStack_20 != (int *)0x0) {
        pcStack_24 = (char *)0x4a3f8b;
        pcStack_24 = (char *)FUN_004aaa00();
        piStack_28 = (int *)0x180;
        pcStack_2c = s_D__work_libs_DX3D_text_cpp_004fca28;
        piStack_30 = (int *)s__s__d____D3DError_texture_load___004fcbd0;
        piStack_34 = (int *)0x4a3fa0;
        FUN_004afee0();
      }
      *(undefined4 *)(param_1 + 0x30) = 1;
    }
    piStack_20 = (int *)auStack_8;
    pcStack_24 = (char *)0x4a4095;
    FUN_004a4a30();
    piStack_28 = *(int **)(param_1 + 4);
    piStack_20 = (int *)auStack_8;
    pcStack_24 = (char *)0x8;
    pcStack_2c = (char *)0x4a40a8;
    piStack_20 = (int *)(**(code **)(*piStack_28 + 0x74))();
    if (piStack_20 != (int *)0x0) {
      pcStack_24 = (char *)0x4a40b2;
      pcStack_24 = (char *)FUN_004b0190();
      piStack_28 = (int *)0x1a4;
      pcStack_2c = s_D__work_libs_DX3D_text_cpp_004fca28;
      piStack_30 = (int *)s__s__d____failed_to_set_memory_co_004fcb24;
      piStack_34 = (int *)0x4a40c7;
      FUN_004afee0();
    }
    iVar6 = param_3;
    if (param_3 != 4) {
      piStack_28 = *(int **)(param_1 + 8);
      piStack_20 = (int *)auStack_8;
      pcStack_24 = (char *)0x8;
      pcStack_2c = (char *)0x4a40e3;
      piStack_20 = (int *)(**(code **)(*piStack_28 + 0x74))();
      if (piStack_20 != (int *)0x0) {
        pcStack_24 = (char *)0x4a40ed;
        pcStack_24 = (char *)FUN_004b0190();
        piStack_28 = (int *)0x1a8;
        pcStack_2c = s_D__work_libs_DX3D_text_cpp_004fca28;
        piStack_30 = (int *)s__s__d____D3DError_SetColorKey_____004fcafc;
        piStack_34 = (int *)0x4a4102;
        FUN_004afee0();
      }
    }
    piStack_20 = (int *)0x4a410f;
    iVar5 = FUN_004ae830();
    if (iVar5 == 0) {
      piStack_28 = *(int **)(param_1 + 0xc);
      pcStack_24 = (char *)DAT_006a621c;
      pcStack_2c = (char *)0x4a4171;
      piStack_20 = (int *)param_1;
      iVar6 = (**(code **)(*piStack_28 + 0xc))();
      if (iVar6 != 0) {
        pcStack_24 = (char *)0x4a417b;
        piStack_20 = (int *)iVar6;
        pcStack_24 = (char *)FUN_004aaa00();
        piStack_28 = (int *)0x1be;
LAB_004a4181:
        pcStack_2c = s_D__work_libs_DX3D_text_cpp_004fca28;
        piStack_30 = (int *)s__s__d____D3DError_get_texturehan_004fcad0;
        piStack_34 = (int *)0x4a4190;
        FUN_004afee0();
      }
      goto LAB_004a4193;
    }
    if (iVar6 == 4) goto LAB_004a4193;
    piStack_28 = *(int **)(param_1 + 0x10);
    pcStack_24 = (char *)DAT_006a621c;
    pcStack_2c = (char *)0x4a4129;
    piStack_20 = (int *)param_1;
    iVar6 = (**(code **)(*piStack_28 + 0xc))();
    if (iVar6 == 0) goto LAB_004a4193;
    if (iVar6 != -0x7789fd1e) {
      pcStack_24 = (char *)0x4a4158;
      piStack_20 = (int *)iVar6;
      pcStack_24 = (char *)FUN_004aaa00();
      piStack_28 = (int *)0x1b1;
      goto LAB_004a4181;
    }
    piStack_20 = *(int **)(param_1 + 0x10);
    pcStack_24 = (char *)0x4a413d;
    (**(code **)(*piStack_20 + 8))();
    piStack_20 = (int *)0x4a4147;
    iVar6 = FUN_004ae830();
    bVar1 = true;
    if (iVar6 == 0) {
LAB_004a4193:
      puVar2 = &DAT_006ab7c8;
      ppcVar7 = &pcStack_3c;
      for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
        *ppcVar7 = (char *)*puVar2;
        puVar2 = puVar2 + 1;
        ppcVar7 = ppcVar7 + 1;
      }
      FUN_004b5c20();
      return 0;
    }
  } while( true );
}

