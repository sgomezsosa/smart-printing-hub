# ADR-001 - Monorepo Strategy

## Status

Accepted

---

## Context

The project contains multiple independent modules:

* IoT Firmware
* Backend Services
* Frontend Applications
* Infrastructure

A repository strategy was required.

---

## Decision

Use a monorepo structure.

```text
smartprint-hub/
├── backend/
├── frontend/
├── infra/
└── iot/
```

---

## Rationale

Benefits:

* Shared visibility
* Unified documentation
* Easier onboarding
* Simplified architecture evolution
* Better alignment between modules

---

## Consequences

Positive:

* Single source of truth
* Centralized documentation
* Easier architecture governance

Negative:

* Larger repository
* Requires stronger structure and discipline

---

## Future Review

Review after introduction of multiple backend services.
