# Resonador-432: Mechanical resonance (vibration) therapy for cancer

[![DOI](https://zenodo.org/badge/DOI/10.5281/zenodo.19342270.svg)](https://doi.org/10.5281/zenodo.19342270)
[![License](https://img.shields.io/badge/License-Proprietary-red.svg)](LICENSE)
[![ES](https://img.shields.io/badge/Spanish-version-green.svg)](./README.md)

**It is not magnetic. It is vibrational.**

Conventional cancer treatments (chemotherapy, radiation) are invasive, aggressive, and have severe side effects. Magnetic resonance imaging (MRI) is diagnostic, not therapeutic.

Resonador-432 explores a different path: using specific vibration frequencies to induce mechanical effects on tumor cells.

## What it does

The device generates vibrations in the range of 432 Hz and its harmonics. It is controlled by an ESP32 and uses an MPU-6050 accelerometer to measure real vibration and adjust it in real time.

Operating modes:
- Fixed frequency.
- Linear sweep (sweeps through a frequency range).
- Logarithmic sweep.
- Pulse modulation.

Main components:
- Vibration generator: DC motor + coil or piezoelectric element.
- Control: ESP32 (custom firmware).
- Sensor: MPU-6050 accelerometer.
- Power: 5V DC.

## Who it is for

- Researchers in biophysics and vibration therapy.
- Developers of experimental medical devices.
- Collaborators interested in preclinical validation.

## Current status

- Functional firmware.
- Electronic schematics documented.
- Control algorithms implemented.
- Functional prototype (pending biological testing).
- Clinical validation (pending).

## Important notice

This is an applied research project. It is not a commercial medical device nor has it been clinically validated. It is shared for scientific exploration and collaborative development.

## Related projects

- CORPUS — artificial body systems
- ENA — brain-machine interface
- OsteoFlux — adaptive vibration for osteoporosis

## License

Copyright © 2026 Enrique Aguayo. All rights reserved.

This project is protected by copyright.

PERMITTED:
- Non-commercial use for educational or research purposes.
- Distribution without modification, as long as this license is maintained and credit is given to the author.

PROHIBITED without express written authorization:
- Commercial use (including, but not limited to: offering it as a service, SaaS, subscription, integration into revenue-generating products, or any use that generates direct or indirect economic benefit).
- Modification for production environments.
- Distribution of modified versions without authorization.

For commercial licenses, technical support, enterprise pilots, or inquiries:
Contact: eaguayo@migst.cl

Any use outside the permitted terms requires prior authorization from the author.

Commercial inquiries are welcome and will be answered within a maximum of 7 business days.

## Author

Enrique Aguayo H.
Mackiber Labs
Contact: eaguayo@migst.cl
ORCID: 0009-0004-4615-6825
GitHub: @enriqueherbertag-lgtm

Documentation assisted by Ana (DeepSeek), AI for research and technical optimization.
