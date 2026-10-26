/*
 * FUN_004b4be0 at 004b4be0
 * undefined FUN_004b4be0(void)
 * Address ranges: 004b4be0-004b4d64
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b4be0(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_2c [22];
  short local_16;
  undefined4 local_14;
  short local_c;
  short local_a;
  undefined4 local_4;
  
  if (DAT_006ab7b4 != 0) {
    iVar1 = FUN_004b96d0(param_1);
    if (iVar1 == 0) {
      FUN_004afce0(s___s__00500a64,param_1);
      return 1000;
    }
    iVar2 = FUN_004bf930(local_2c,0x2c,1,iVar1);
    if (iVar2 != 1) {
      FUN_004b9840(iVar1);
      return 0x3e9;
    }
    FUN_004afce0(s_file____s_00500a50,param_1);
    FUN_004afce0(s_bufferlength__d_00500a3c,local_4);
    FUN_004afce0(s_samplerate___d_00500a28,local_14);
    FUN_004afce0(s_bpps___d_00500a14,(int)local_a);
    FUN_004afce0(s_align___d_stereo__d_005009f8,(int)local_c,1 < local_16);
    iVar2 = param_2 * 0x44;
    *(undefined4 *)(iVar2 + 0x3c + DAT_006ab798) = local_4;
    if (*(int *)(iVar2 + 0x34 + DAT_006ab798) == 0) {
      uVar3 = FUN_004b3d20(local_4,local_14,(int)local_a,(int)local_c);
      *(undefined4 *)(iVar2 + 0x28 + DAT_006ab798) = uVar3;
      if (*(int *)(iVar2 + 0x28 + DAT_006ab798) == 0) {
        return 2000;
      }
    }
    else {
      iVar2 = FUN_004b3df0(iVar2 + 0x28 + DAT_006ab798,iVar2 + 0x2c + DAT_006ab798,local_4,local_14,
                           (int)local_a,(int)local_c,1 < local_16);
      if (iVar2 != 0) {
        return 2000;
      }
    }
    FUN_004b4ab0(param_2,iVar1,local_4,0x2c);
    FUN_004b9840(iVar1);
  }
  return 0;
}

