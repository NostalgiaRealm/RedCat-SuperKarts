/*
 * FUN_00407c85 at 00407c85
 * undefined4 __cdecl FUN_00407c85(LPCSTR param_1, int param_2)
 * Address ranges: 00407c85-00407e4a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00407c85(LPCSTR param_1,int param_2)

{
  undefined4 uVar1;
  FILE *pFVar2;
  uint uVar3;
  int iVar4;
  char local_38 [22];
  short local_22;
  int local_20;
  short local_18;
  undefined2 local_16;
  undefined4 local_10;
  uint local_c;
  undefined4 local_8;
  
  if (DAT_0043d43c == 0) {
    uVar1 = 0;
  }
  else {
    pFVar2 = (FILE *)FUN_00409d69(param_1);
    if (pFVar2 == (FILE *)0x0) {
      FUN_004015a6((byte *)s___s__004301f0);
      uVar1 = 1000;
    }
    else {
      uVar3 = FUN_0041f3be(local_38,0x2c,1,(int *)pFVar2);
      if (uVar3 == 1) {
        local_8 = local_10;
        local_c = (uint)(1 < local_22);
        FUN_004015a6((byte *)s_file____s_004301f8);
        FUN_004015a6((byte *)s_bufferlength__d_0043020c);
        FUN_004015a6((byte *)s_samplerate___d_00430220);
        FUN_004015a6((byte *)s_bpps___d_00430234);
        FUN_004015a6((byte *)s_align___d_stereo__d_00430248);
        *(undefined4 *)(DAT_0043d420 + 0x3c + param_2 * 0x44) = local_8;
        if (*(int *)(DAT_0043d420 + 0x34 + param_2 * 0x44) == 0) {
          uVar1 = FUN_00406107(local_8,local_20,local_16,(int)local_18,local_c);
          *(undefined4 *)(DAT_0043d420 + 0x28 + param_2 * 0x44) = uVar1;
          if (*(int *)(DAT_0043d420 + 0x28 + param_2 * 0x44) == 0) {
            return 2000;
          }
        }
        else {
          iVar4 = FUN_004061cb((undefined4 *)(DAT_0043d420 + 0x28 + param_2 * 0x44),
                               DAT_0043d420 + 0x2c + param_2 * 0x44,local_8,local_20,local_16,
                               (int)local_18,local_c);
          if (iVar4 != 0) {
            return 2000;
          }
        }
        FUN_00407b2a(param_2,(int *)pFVar2,local_8,0x2c);
        FUN_00409f20(pFVar2);
        uVar1 = 0;
      }
      else {
        FUN_00409f20(pFVar2);
        uVar1 = 0x3e9;
      }
    }
  }
  return uVar1;
}

