/*
 * FUN_00470f50 at 00470f50
 * undefined FUN_00470f50(void)
 * Address ranges: 00470f50-004710d7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_00470f50(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 uVar4;
  undefined3 extraout_var_02;
  uint uVar5;
  uint uVar6;
  undefined1 *puVar7;
  char *pcVar8;
  undefined1 uVar9;
  undefined1 *in_stack_ffffffd8;
  char *local_18;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d0880;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar2 = FUN_00470560();
  pcVar3 = (&PTR_DAT_004f63d8)[iVar2];
  FUN_0040b4f0(0);
  uVar5 = 0xffffffff;
  pcVar8 = pcVar3;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5 - 1;
  cVar1 = FUN_0040b600(uVar5,1);
  if (cVar1 != '\0') {
    pcVar8 = local_18;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar3;
      pcVar3 = pcVar3 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar6 = uVar5 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar8 = *pcVar3;
      pcVar3 = pcVar3 + 1;
      pcVar8 = pcVar8 + 1;
    }
    local_18[uVar5] = '\0';
  }
  local_4 = 0;
  puVar7 = (undefined1 *)((param_3 + 0xf) * 0x10 + param_1);
  uVar9 = *puVar7;
  FUN_0040b4f0(0);
  FUN_00412870(puVar7,0,0xffffffff);
  local_4 = CONCAT31(local_4._1_3_,1);
  pcVar3 = local_18;
  if (local_18 == (char *)0x0) {
    pcVar3 = "";
  }
  iVar2 = __strcmpi(pcVar3,&DAT_004f671c);
  if (iVar2 == 0) {
    puVar7 = in_stack_ffffffd8;
    if (in_stack_ffffffd8 == (undefined1 *)0x0) {
      puVar7 = &DAT_004d2404;
    }
    FUN_00472e70(param_2,puVar7);
    uVar4 = extraout_var;
  }
  else {
    puVar7 = in_stack_ffffffd8;
    if (in_stack_ffffffd8 == (undefined1 *)0x0) {
      puVar7 = &DAT_004d2404;
    }
    FUN_004b2870(param_2,puVar7,0x19);
    uVar4 = extraout_var_00;
  }
  if (in_stack_ffffffd8 != (undefined1 *)0x0) {
    cVar1 = in_stack_ffffffd8[-1];
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(in_stack_ffffffd8 + -1);
      uVar4 = extraout_var_01;
    }
    else {
      in_stack_ffffffd8[-1] = cVar1 + -1;
    }
  }
  if (local_18 != (char *)0x0) {
    cVar1 = local_18[-1];
    if ((cVar1 != '\0') && (cVar1 != -1)) {
      local_18[-1] = cVar1 + -1;
      ExceptionList = local_c;
      return CONCAT31(uVar4,1);
    }
    FUN_004bc150(local_18 + -1,uVar9,0,0,0);
    uVar4 = extraout_var_02;
  }
  ExceptionList = local_c;
  return CONCAT31(uVar4,1);
}

