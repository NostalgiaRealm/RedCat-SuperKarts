/*
 * FUN_0047913c at 0047913c
 * undefined __register FUN_0047913c(int param_1, char param_2)
 * Address ranges: 0047913c-004791c2;004791e5-004792b7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0047913c(int param_1,char param_2)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 extraout_ECX;
  undefined1 extraout_DL;
  undefined4 *in_FS_OFFSET;
  undefined4 uStackY_44;
  undefined1 *puStackY_40;
  undefined1 *puStackY_3c;
  undefined4 uStackY_38;
  undefined1 *puStackY_34;
  undefined1 *puStackY_30;
  undefined4 in_stack_ffffffd4;
  undefined4 in_stack_ffffffd8;
  undefined *local_10;
  undefined1 local_9;
  int local_8;
  
  uVar3 = 0;
  local_10 = (undefined *)0x0;
  local_9 = 0;
  if (param_2 != '\0') {
    puStackY_30 = (undefined1 *)0x479156;
    param_1 = FUN_004031ac(param_1,param_2,0,in_stack_ffffffd4,in_stack_ffffffd8);
    uVar3 = extraout_ECX;
    local_9 = extraout_DL;
  }
  puStackY_34 = &LAB_004792b8;
  uStackY_38 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStackY_38;
  puStackY_40 = &LAB_004791c3;
  uStackY_44 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStackY_44;
  puStackY_3c = &stack0xfffffffc;
  puStackY_30 = &stack0xfffffffc;
  local_8 = param_1;
  piVar2 = FUN_00455100((int *)FUN_004558bc,'\x01',uVar3);
  *(int **)PTR_DAT_0047c740 = piVar2;
  FUN_00403e90((int *)&local_10,3);
  FUN_00455320(*(int *)PTR_DAT_0047c740,local_10);
  *in_FS_OFFSET = "trans.dat";
  FUN_00403e1c((int *)(*(int *)PTR_DAT_0047c86c + 0x40),*(undefined4 **)PTR_DAT_0047c694,
               (undefined4 *)"rcsk.hlp");
  if (*(int *)PTR_DAT_0047c740 != 0) {
    FUN_0047931c();
    FUN_004795d4();
    FUN_004551a0(*(int **)PTR_DAT_0047c740);
    FUN_0047966c();
    cVar1 = FUN_0045bba8(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c));
    if (cVar1 == '\x05') {
      FUN_0045c518(*(byte *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80) + 0x22),0x1b,1);
    }
    cVar1 = FUN_0045bba8(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c));
    if (cVar1 == '\x05') {
      *(undefined4 *)PTR_DAT_0047c5cc = 0xff;
    }
    else {
      *(undefined4 *)PTR_DAT_0047c5cc = 0x28;
    }
    FUN_004557c0(*(int *)PTR_DAT_0047c740);
  }
  FUN_00432448();
  *in_FS_OFFSET = uStackY_44;
  puStackY_3c = &LAB_004792bf;
  puStackY_40 = (undefined1 *)0x4792b7;
  FUN_00403b50((int *)&local_10);
  return;
}

