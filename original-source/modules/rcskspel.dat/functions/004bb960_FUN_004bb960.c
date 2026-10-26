/*
 * FUN_004bb960 at 004bb960
 * undefined FUN_004bb960(void)
 * Address ranges: 004bb960-004bb9d2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004bb960(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_004bbc00(param_1);
  iVar1 = *(int *)(DAT_006b5c10 + 8 + iVar1 * 0x1c);
  if ((iVar1 == -1) || ((&DAT_006b5d48)[iVar1 * 0x1c] == '\0')) {
    FUN_004afee0(s__s__d_____dispatch_form_message__005022cc,
                 s_C__libraries_dxdraw_Forms_cpp_00502310,0x3c,iVar1);
  }
  else if (*(code **)(&DAT_006b5d60 + iVar1 * 0x1c) != (code *)0x0) {
    uVar2 = (**(code **)(&DAT_006b5d60 + iVar1 * 0x1c))(param_1,param_2,param_3,param_4);
    return uVar2;
  }
  return 0;
}

