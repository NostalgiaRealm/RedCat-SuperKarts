/*
 * FUN_00471aa4 at 00471aa4
 * undefined FUN_00471aa4(void)
 * Address ranges: 00471aa4-00471b69
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00471aa4(int param_1)

{
  int iVar1;
  undefined *puVar2;
  char cVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 uVar4;
  
  puVar2 = PTR_DAT_0047c670;
  FUN_00471944(param_1);
  FUN_00471a14(param_1);
  cVar3 = FUN_0045bba8(*(int *)(*(int *)puVar2 + 0x7c));
  if (cVar3 == '\x01') {
    iVar1 = *(int *)(*(int *)(*(int *)puVar2 + 0x7c) + 0x14);
    if (iVar1 != -1) {
      FUN_004578f4(*(int *)(*(int *)puVar2 + 0x98),iVar1);
      FUN_0045792c(*(undefined4 *)(*(int *)puVar2 + 0x98),
                   *(undefined4 *)(*(int *)(*(int *)puVar2 + 0x7c) + 0x14));
    }
  }
  else {
    FUN_00457904();
  }
  FUN_00458480(*(int *)(*(int *)puVar2 + 0x90),*(int *)(*(int *)(*(int *)puVar2 + 0x80) + 0x14));
  FUN_00472494(param_1);
  FUN_00472004(param_1);
  FUN_00472194(param_1);
  cVar3 = FUN_0045bba8(*(int *)(*(int *)puVar2 + 0x7c));
  if (cVar3 == '\x01') {
    FUN_0045bbac(*(int *)(*(int *)puVar2 + 0x7c),3);
    uVar4 = extraout_var_00;
  }
  else {
    uVar4 = extraout_var;
    if (cVar3 == '\x02') {
      FUN_0045bbac(*(int *)(*(int *)puVar2 + 0x7c),4);
      uVar4 = extraout_var_01;
    }
  }
  return CONCAT31(uVar4,1);
}

