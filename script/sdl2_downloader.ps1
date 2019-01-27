# =======================================================
# NAME: sdl2_downloader.ps1
# AUTHOR: ***REMOVED***
# DATE: 30/07/2018
#
# VERSION 1
# COMMENTS: Download SDL2, SDL2_ttf and SDL2_mixer for ICEngine and put them in one SDL2 folder
#
# =======================================================

Add-Type -AssemblyName System.IO.Compression.FileSystem
function Unzip
{
    param([string]$zipfile, [string]$outpath)
    [System.IO.Compression.ZipFile]::ExtractToDirectory($zipfile, $outpath)
}

$PathFolder = "$($PSScriptRoot)\..\external"

#PRECLEAN

if (Test-Path "$($PathFolder)") 
{
    Remove-Item -path "$($PathFolder)" -Recurse
}

#FOLDER CREATION

New-Item -ItemType directory -Path "$($PathFolder)" | Out-Null
New-Item -ItemType directory -Path "$($PathFolder)\SDL2\include\SDL2" | Out-Null
New-Item -ItemType directory -Path "$($PathFolder)\SDL2\lib\x86" | Out-Null
New-Item -ItemType directory -Path "$($PathFolder)\SDL2\lib\x64" | Out-Null

# DOWNLOAD
########################### SDL2 ###################################################
Write-Output "SDL2 download..."
(New-Object Net.WebClient).DownloadFile('https://www.libsdl.org/release/SDL2-devel-2.0.9-VC.zip', "$($PathFolder)\SDL2.zip")
Unzip "$($PathFolder)\SDL2.zip" $PathFolder"."
Rename-Item -path "$($PathFolder)\SDL2-2.0.9" -NewName "_SDL2"
Write-Output "Complete"
########################### SDL2_ttf ###############################################
Write-Output "SDL2_ttf download..."
(New-Object Net.WebClient).DownloadFile('https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-devel-2.0.15-VC.zip', "$($PathFolder)\SDL2_ttf.zip")
Unzip "$($PathFolder)\SDL2_ttf.zip" $PathFolder"."
Rename-Item -path "$($PathFolder)\SDL2_ttf-2.0.15" -NewName "_SDL2_ttf"
Write-Output "Complete"
########################### SDL2_mixer ##########################################
Write-Output "SDL2_mixer download..."
(New-Object Net.WebClient).DownloadFile('https://www.libsdl.org/projects/SDL_mixer/release/SDL2_mixer-devel-2.0.4-VC.zip', "$($PathFolder)\SDL2_mixer.zip")
Unzip "$($PathFolder)\SDL2_mixer.zip" "$($PathFolder)"
Rename-Item -path "$($PathFolder)\SDL2_mixer-2.0.4" -NewName "_SDL2_mixer"
Write-Output "Complete"

#################################################################################
#################################################################################
Write-Output "Moving all include to SDL2 folder..."
#include
Get-ChildItem -Path "$($PathFolder)\_SDL2\include" -Recurse -File | Move-Item -Destination "$($PathFolder)\SDL2\include\SDL2"
Get-ChildItem -Path "$($PathFolder)\_SDL2_ttf\include" -Recurse -File | Move-Item -Destination "$($PathFolder)\SDL2\include\SDL2"
Get-ChildItem -Path "$($PathFolder)\_SDL2_mixer\include" -Recurse -File | Move-Item -Destination "$($PathFolder)\SDL2\include\SDL2"
Write-Output "Complete"
#libs
    #x86
Write-Output "Moving all libs to SDL2 folder..."
Get-ChildItem -Path "$($PathFolder)\_SDL2\lib\x86" -Recurse -File | Move-Item -Destination "$($PathFolder)\SDL2\lib\x86" -force 
Get-ChildItem -Path "$($PathFolder)\_SDL2_ttf\lib\x86" -Recurse -File | Move-Item -Destination "$($PathFolder)\SDL2\lib\x86" -force 
Get-ChildItem -Path "$($PathFolder)\_SDL2_mixer\lib\x86" -Recurse -File | Move-Item -Destination "$($PathFolder)\SDL2\lib\x86" -force 

    #x64
Get-ChildItem -Path "$($PathFolder)\_SDL2\lib\x64" -Recurse -File | Move-Item -Destination "$($PathFolder)\SDL2\lib\x64" -force 
Get-ChildItem -Path "$($PathFolder)\_SDL2_ttf\lib\x64" -Recurse -File | Move-Item -Destination "$($PathFolder)\SDL2\lib\x64" -force 
Get-ChildItem -Path "$($PathFolder)\_SDL2_mixer\lib\x64" -Recurse -File | Move-Item -Destination "$($PathFolder)\SDL2\lib\x64" -force 
Write-Output "Complete"

#############################################################################
#CLEAN
Write-Output "Starting cleaning..."
    #ZIP
Remove-Item -path "$($PathFolder)\SDL2.zip"
Remove-Item -path "$($PathFolder)\SDL2_mixer.zip"
Remove-Item -path "$($PathFolder)\SDL2_ttf.zip"
    #FOLDER
Remove-Item -path "$($PathFolder)\_SDL2" -Recurse
Remove-Item -path "$($PathFolder)\_SDL2_ttf" -Recurse
Remove-Item -path "$($PathFolder)\_SDL2_mixer" -Recurse
Write-Output "Complete"