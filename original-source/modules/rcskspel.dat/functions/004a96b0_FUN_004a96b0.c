/*
 * FUN_004a96b0 at 004a96b0
 * undefined FUN_004a96b0(void)
 * Address ranges: 004a96b0-004a98f1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004a96b0(int *param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar4 = DAT_006a6284;
  bVar1 = false;
  if (param_1[2] == 1) {
    if (DAT_006a6284 != 2) {
      bVar1 = true;
      if (DAT_006a6234 != 1) {
        FUN_004afee0(s__s__d____device_was_not_initiali_004fc8ac,s___d3dev_h_004fc8d4,0xb8);
      }
      if (DAT_006a6284 != 2) {
        DAT_006a6284 = 2;
        iVar2 = (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,8,2);
        if (iVar2 != 0) {
          uVar3 = FUN_004aaa00(iVar2);
          FUN_004afee0(s__s__d_____FILL_MODE__error_setti_004e8950,s___d3dev_inl_004fc8a0,0x1ce,
                       uVar3);
        }
      }
    }
  }
  else if ((param_1[2] == 2) && (DAT_006a6284 != 1)) {
    if (DAT_006a6234 != 1) {
      FUN_004afee0(s__s__d____device_was_not_initiali_004fc8ac,s___d3dev_h_004fc8d4,0xb8);
    }
    if (DAT_006a6284 != 1) {
      DAT_006a6284 = 1;
      iVar2 = (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,8,1);
      if (iVar2 != 0) {
        uVar3 = FUN_004aaa00(iVar2);
        FUN_004afee0(s__s__d_____FILL_MODE__error_setti_004e8950,s___d3dev_inl_004fc8a0,0x1ce,uVar3)
        ;
      }
    }
    bVar1 = true;
  }
  if (*param_1 == 1) {
    iVar2 = (**(code **)(*DAT_006a621c + 0x78))
                      (DAT_006a621c,4,1,param_1[0x1e],param_1[0x1f],param_1[0x26],param_1[0x27],8);
    if (iVar2 == 0) goto LAB_004a988b;
    if (param_1[0x2b] == 0) {
      FUN_004afee0(s__s__d____string_is_not_initialis_004fb8fc,s___str_h_004fcac4,0x24);
    }
    iVar6 = param_1[0x2a];
    uVar3 = FUN_004aaa00(iVar2);
    uVar5 = 0x2b5;
  }
  else {
    if (*param_1 != 2) goto LAB_004a988b;
    iVar2 = (**(code **)(*DAT_006a621c + 0x78))
                      (DAT_006a621c,4,2,param_1[0x20],param_1[0x21],param_1[0x26],param_1[0x27],8);
    if (iVar2 == 0) goto LAB_004a988b;
    if (param_1[0x2b] == 0) {
      FUN_004afee0(s__s__d____string_is_not_initialis_004fb8fc,s___str_h_004fcac4,0x24);
    }
    iVar6 = param_1[0x2a];
    uVar3 = FUN_004aaa00(iVar2);
    uVar5 = 0x2c1;
  }
  FUN_004afee0(s__s__d____D3DError_DrawPrimitive___004fd29c,s_D__work_libs_DX3D_Mesh_cpp_004fd124,
               uVar5,iVar6,uVar3);
LAB_004a988b:
  if (bVar1) {
    if (DAT_006a6234 != 1) {
      FUN_004afee0(s__s__d____device_was_not_initiali_004fc8ac,s___d3dev_h_004fc8d4,0xb8);
    }
    if (DAT_006a6284 != iVar4) {
      DAT_006a6284 = iVar4;
      iVar4 = (**(code **)(*DAT_006a621c + 0x5c))(DAT_006a621c,8,iVar4);
      if (iVar4 != 0) {
        uVar3 = FUN_004aaa00(iVar4);
        FUN_004afee0(s__s__d_____FILL_MODE__error_setti_004e8950,s___d3dev_inl_004fc8a0,0x1ce,uVar3)
        ;
      }
    }
  }
  return;
}

