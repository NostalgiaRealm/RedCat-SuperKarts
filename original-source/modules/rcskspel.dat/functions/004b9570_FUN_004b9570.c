/*
 * FUN_004b9570 at 004b9570
 * undefined FUN_004b9570(void)
 * Address ranges: 004b9570-004b96c1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b9570(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == 0) {
    FUN_004afee0(s__s__d____null_ptr_assignment___005019c4,s_C__libraries_dxdraw_Fileio_cpp_00501928
                 ,0xaf);
  }
  if (DAT_006ab944 == 0) {
    uVar1 = FUN_004c0331(param_1,param_2,param_3);
    return uVar1;
  }
  iVar2 = FUN_004ccbb9(DAT_006ab934);
  iVar3 = FUN_004ccbb9(param_1);
  if (iVar3 != iVar2) {
    uVar1 = FUN_004c0331(param_1,param_2,param_3);
    return uVar1;
  }
  if (param_3 != 0) {
    if (param_3 == 1) {
      uVar1 = FUN_004c0331(DAT_006ab934,DAT_006ab940 + param_2,0);
      return uVar1;
    }
    if (param_3 != 2) {
      FUN_004afee0(s__s__d____illegal_fseek_cmd__005019a4,s_C__libraries_dxdraw_Fileio_cpp_00501928,
                   0xd4);
      return 0x3e9;
    }
    if (DAT_006ab92c < DAT_006ab92c + param_2) {
      FUN_004afee0(s__s__d____fseeking_past_end_file__00501978,
                   s_C__libraries_dxdraw_Fileio_cpp_00501928,0xcd,DAT_006ab940,DAT_006ab92c,param_2)
      ;
      return 0x3e9;
    }
    uVar1 = FUN_004c0331(DAT_006ab934,DAT_006ab92c + param_2,0);
    return uVar1;
  }
  param_2 = DAT_006ab940 + param_2;
  if ((param_2 <= DAT_006ab92c) && (DAT_006ab940 <= param_2)) {
    uVar1 = FUN_004c0331(DAT_006ab934,param_2,0);
    return uVar1;
  }
  FUN_004afee0(s__s__d____fseeking_past_end_or_be_00501948,s_C__libraries_dxdraw_Fileio_cpp_00501928
               ,0xc5);
  return 0x3e9;
}

