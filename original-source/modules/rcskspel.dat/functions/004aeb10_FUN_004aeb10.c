/*
 * FUN_004aeb10 at 004aeb10
 * undefined FUN_004aeb10(void)
 * Address ranges: 004aeb10-004aebe4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __thiscall FUN_004aeb10(int param_1,uint param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x198) != 1) {
    FUN_004afee0(s__s__d____error_description_is_no_004fe498,
                 s_D__work_libs_DX3D_D3devdsc_cpp_004fe4c8,0xc3);
  }
  if ((int)param_2 < 0x101) {
    if (param_2 == 0x100) goto LAB_004aeba9;
    switch(param_2) {
    case 8:
      param_2 = 0x800;
      break;
    default:
      goto switchD_004aeb51_caseD_9;
    case 0x10:
      param_2 = 0x400;
      break;
    case 0x18:
      param_2 = 0x200;
      break;
    case 0x20:
      param_2 = 0x100;
    }
  }
  else {
    if (((param_2 == 0x200) || (param_2 == 0x400)) || (param_2 == 0x800)) goto LAB_004aeba9;
switchD_004aeb51_caseD_9:
    FUN_004afee0(s__s__d____unknown_render_bitdepth_004fe4e8,
                 s_D__work_libs_DX3D_D3devdsc_cpp_004fe4c8,0xd9,param_2);
  }
LAB_004aeba9:
  iVar1 = FUN_004ae830();
  if (iVar1 == 0) {
    if ((*(byte *)(param_1 + 0xd0) & 0x80) != 0) {
      return *(uint *)(param_1 + 0x168) & param_2;
    }
  }
  else if ((*(byte *)(param_1 + 4) & 0x80) != 0) {
    return *(uint *)(param_1 + 0x9c) & param_2;
  }
  return 0xffffffff;
}

