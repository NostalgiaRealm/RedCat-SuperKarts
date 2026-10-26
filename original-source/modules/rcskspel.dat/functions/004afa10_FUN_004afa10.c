/*
 * FUN_004afa10 at 004afa10
 * undefined FUN_004afa10(void)
 * Address ranges: 004afa10-004afb0f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004afa10(uint param_1)

{
  int iVar1;
  int iVar2;
  
  if (DAT_006a63fc != 0) {
    if (DAT_006a63fc == 1) {
      FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,&DAT_006a641d,&DAT_006a6404,
                   DAT_006a63f4);
      FUN_004bc150(DAT_006a63f0);
    }
    if (DAT_006a63fc != 0) {
      FUN_004bc150(DAT_006a6400);
      DAT_006a63fc = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  if ((int)param_1 < 0) {
    FUN_004afee0(s__s__d____T_ARRAY_construction__i_004de770,s___array_hpp_004fc894,0x107,
                 &DAT_006a641d,&DAT_006a6404,param_1);
  }
  DAT_006a63f0 = operator_new(param_1 * 4);
  DAT_006a63f4 = param_1;
  _DAT_006a63f8 = 0;
  DAT_006a6400 = operator_new(param_1);
  FUN_004afce0(s_T_ARRAY___alloc___16_16s___16_16_004de744,&DAT_006a641d,&DAT_006a6404,DAT_006a63f4)
  ;
  DAT_006a63fc = 1;
  iVar1 = 0;
  if (0 < (int)param_1) {
    do {
      iVar2 = iVar1 + 1;
      *(undefined1 *)((int)DAT_006a6400 + iVar1) = 0;
      iVar1 = iVar2;
    } while (iVar2 < (int)param_1);
  }
  return 0;
}

